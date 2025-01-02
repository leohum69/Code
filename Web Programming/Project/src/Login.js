import React, { useState } from "react";
import { auth, db, firebaseCreateUserWithEmailAndPassword, firebaseSignInWithEmailAndPassword, setDoc, doc, getDoc } from "./Auth";

const LoginPage = () => {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [userType, setUserType] = useState("student");

  // Function to set a cookie
  const setCookie = (name, value, days) => {
    const expires = new Date();
    expires.setTime(expires.getTime() + days * 24 * 60 * 60 * 1000);
    document.cookie = `${name}=${value};expires=${expires.toUTCString()};path=/`;
  };

  // Signup Function
  const handleSignup = async () => {
    try {
      // Create user in Firebase Auth
      const userCredential = await firebaseCreateUserWithEmailAndPassword(auth, email, password);
      const user = userCredential.user;
  
      // Save userType and purchasedCourses in Firestore
      await setDoc(doc(db, "users", user.uid), { 
        email, 
        userType, 
        purchasedCourses: [] 
      });
  
      alert("Signup successful! You can now log in with your credentials.");
    } catch (error) {
      console.error("Error during signup:", error);
      alert(`Signup failed: ${error.message}`);
    }
  };
  

  // Login Function
  const handleLogin = async () => {
    try {
      // Sign in user with Firebase Auth
      const userCredential = await firebaseSignInWithEmailAndPassword(auth, email, password);
      const user = userCredential.user;

      // Retrieve userType and purchasedCourses from Firestore
      const userDoc = await getDoc(doc(db, "users", user.uid));
      if (userDoc.exists()) {
        const userData = userDoc.data();
        if (userData.userType === userType) {
          // Set the userId in a cookie instead of localStorage
          setCookie("userId", user.uid, 7);  // Cookie expires in 7 days

          // Redirect based on userType (this could be to different home pages for student/teacher)
          if (userType === "student") {
            window.location.href = "/home"; // Redirect to student home
          } else if (userType === "teacher") {
            window.location.href = "/home"; // Redirect to teacher home
          }
        } else {
          alert("User type mismatch! Please check your credentials.");
        }
      } else {
        alert("User data not found! Contact support.");
      }
    } catch (error) {
      console.error("Error during login:", error);
      alert("Login failed. Please check your credentials and try again.");
    }
  };

  return (
    <div className="login-container">
      <h2>Login</h2>
      <form id="login-form">
        <div>
          <label htmlFor="user-type">Login As:</label>
          <select
            id="user-type"
            name="user-type"
            value={userType}
            onChange={(e) => setUserType(e.target.value)}
          >
            <option value="student">Student</option>
            <option value="teacher">Teacher</option>
          </select>
        </div>
        <input
          type="text"
          id="email"
          placeholder="Email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
          required
        />
        <input
          type="password"
          id="password"
          placeholder="Password"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
          required
        />
        <button type="button" onClick={handleLogin}>
          Login
        </button>
        <button type="button" onClick={handleSignup}>
          Signup
        </button>
      </form>
    </div>
  );
};

export default LoginPage;
