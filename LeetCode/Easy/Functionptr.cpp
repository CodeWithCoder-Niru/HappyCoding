#include<iostream>
///int val =10;
int fun1(int j)
{
    std::cout<<"Function1 \n";
    std::cout<<j << "\n";
    return j;
}

int fun2(int i)
{
    std::cout<<"Function2 \n";
    std::cout<<i <<std::endl;
    return i;
}


// int main()
// {
//     void (*function_ptr) () = fun2;
//     function_ptr();
//     // for(int i=0;i<2;i++)
//     // {
//     //     (*function_ptr[i])();
//     // }
// }

struct Dummy_struct{
    int signal;
    int (*function_ptr)(int);
    int (*strSize)(struct Dummy_struct *, int);
};

int fun1_strcture(Dummy_struct *temp, int size)
{
  std::cout<<"Size of struct = "<<sizeof(Dummy_struct)<<std::endl;
  return size/sizeof(Dummy_struct);
}

int main()
{
      Dummy_struct obj_Dummy_struct[] = {
      {
        0,
        fun1,
        fun1_strcture,
      },

      {
        5,
        fun2,
        fun1_strcture,
      }

    };
    //std::cout<<"Sizeof obj"<<sizeof(obj_Dummy_struct)/sizeof(obj_Dummy_struct[0])<<std::endl;
    for(int i=0;i<2;i++)
    {
      std::cout<<"Sizeof obj"<<sizeof(obj_Dummy_struct)/sizeof(obj_Dummy_struct[0])<<std::endl;
      std::cout<<"Sizeof obj 2 "<<sizeof(obj_Dummy_struct)<<std::endl;
      // (obj_Dummy_struct.function_ptr[i]);
      auto ptr = obj_Dummy_struct[i];
      std::cout<<"Signal = "<<ptr.signal<<std::endl;
      std::cout<<ptr.function_ptr(i)<<std::endl;
      std::cout<<ptr.strSize(&obj_Dummy_struct[i], sizeof(obj_Dummy_struct))<<std::endl;
    }
}
