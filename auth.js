import { initializeApp } from "https://www.gstatic.com/firebasejs/10.7.1/firebase-app.js";
import {
  getAuth,
  GithubAuthProvider,
  signInWithPopup,
  onAuthStateChanged
} from "https://www.gstatic.com/firebasejs/10.7.1/firebase-auth.js";

const firebaseConfig = {
  apiKey: "AIzaSyBbM6c9r5NIZ_0FjzmBqhx8vTbgCTUsM-I",
  authDomain: "codelock-4db77.firebaseapp.com",
  projectId: "codelock-4db77",
  storageBucket: "codelock-4db77.firebasestorage.app",
  messagingSenderId: "457021445542",
  appId: "1:457021445542:web:4f72fb4a110b1888642b67"
};

const app = initializeApp(firebaseConfig);
const auth = getAuth(app);
const provider = new GithubAuthProvider();

document.getElementById("loginBtn").onclick = () => {
  signInWithPopup(auth, provider);
};

// 🔹 Logout button
document.getElementById("logoutBtn").onclick = () => {
  signOut(auth).then(() => {
    document.getElementById("login-container").style.display = "block";
    document.getElementById("content").style.display = "none";
  });
};

// 🔹 Auth state listener
onAuthStateChanged(auth, user => {
  if (user) {
    window.location.href = "https://github.com/Niranjan123-12/HappyCoding";
    document.getElementById("login-container").style.display = "none";
    document.getElementById("content").style.display = "block";
  } else {
    // User is not logged in → show login screen
    document.getElementById("login-container").style.display = "block";
    document.getElementById("content").style.display = "none";
  }
});
