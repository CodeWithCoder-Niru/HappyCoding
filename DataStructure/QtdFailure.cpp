#include <sys/inotify.h>
#include <sys/inotify_ext.h>

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

static void handle_qnx_extended_event(struct inotify_event* event)
{
    if (event == NULL)
    {
        return;
    }

    /*
     * QNX extended events come with mask == 0.
     * For normal file events, mask will contain IN_CREATE, IN_MODIFY, etc.
     */
    if (event->mask != 0)
    {
        return;
    }

    inotify_qnx_ext_hdr* hdr =
        reinterpret_cast<inotify_qnx_ext_hdr*>(&event->name[0]);

    if (hdr == NULL)
    {
        return;
    }

    switch (hdr->type)
    {
        case INOTIFY_QNX_EXT_SECURITY:
        {
            inotify_qnx_ext_security_t* sec =
                reinterpret_cast<inotify_qnx_ext_security_t*>(hdr);

            if (sec->subtype ==
                INOTIFY_QNX_EXT_SECURITY_BLOCK_VALIDATION_FAILED)
            {
                struct blk_validation_failure* bfail =
                    &(sec->payload.blk_hash);

                printf("QTD integrity validation failed\n");
                printf("Failed block number: %" PRIu64 "\n", bfail->blkno);
                printf("Hash block number  : %u\n", bfail->hashblkno);

                /*
                 * Here IDS should generate:
                 * Security Event: 0xD706 OS_LOG_REPORTS
                 */
            }

            break;
        }

        default:
        {
            printf("Other QNX extended event received, type=%u\n", hdr->type);
            break;
        }
    }
}

int main()
{
    int fd = inotify_init();

    if (fd == -1)
    {
        printf("inotify_init failed: %s\n", strerror(errno));
        return 1;
    }

    int ret = inotify_qnx_ext(fd, INOTIFY_QNX_EXT_SECURITY);

    if (ret == -1)
    {
        printf("inotify_qnx_ext failed: %s\n", strerror(errno));
        close(fd);
        return 1;
    }

    printf("Listening for QTD security/integrity events...\n");

    char buffer[4096];

    while (true)
    {
        ssize_t bytes = read(fd, buffer, sizeof(buffer));

        if (bytes < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }

            printf("read failed: %s\n", strerror(errno));
            break;
        }

        size_t offset = 0;

        while (offset < static_cast<size_t>(bytes))
        {
            struct inotify_event* event =
                reinterpret_cast<struct inotify_event*>(&buffer[offset]);

            handle_qnx_extended_event(event);

            offset += sizeof(struct inotify_event) + event->len;
        }
    }

    close(fd);
    return 0;
}