// Import necessary Firebase services from CDN
import { initializeApp } from "https://www.gstatic.com/firebasejs/11.0.2/firebase-app.js";
import {
  getAuth,
  createUserWithEmailAndPassword as firebaseCreateUserWithEmailAndPassword,
  signInWithEmailAndPassword as firebaseSignInWithEmailAndPassword,
} from "https://www.gstatic.com/firebasejs/11.0.2/firebase-auth.js";
import {
  getFirestore,
  doc,
  setDoc,
  getDoc,
  updateDoc,
  arrayUnion,
} from "https://www.gstatic.com/firebasejs/11.0.2/firebase-firestore.js";

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyBjH7hccRE0B9i4qMAFHYNTEcAImYlq30g", //use your own key to see progress cuz its on my acc
  authDomain: "project-5a928.firebaseapp.com",
  projectId: "project-5a928",
  storageBucket: "project-5a928.firebasestorage.app",
  messagingSenderId: "208997622859",
  appId: "1:208997622859:web:7df18da076e16fb0f399ce",
  measurementId: "G-ED63QM4NWP",
};

// Initialize Firebase app
const app = initializeApp(firebaseConfig);

// Get Firebase services
const auth = getAuth(app);   // Firebase Authentication
const db = getFirestore(app); // Firestore database

// Exporting Firebase services and methods
export {
  auth,
  db,
  firebaseCreateUserWithEmailAndPassword,
  firebaseSignInWithEmailAndPassword,
  setDoc,
  doc,
  getDoc,
  updateDoc,
  arrayUnion,
};
