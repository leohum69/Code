import React, { useState, useEffect } from "react";
import { db } from "./Auth"; // Assuming Firebase has been initialized in Auth.js
import { doc, getDoc } from "https://www.gstatic.com/firebasejs/11.0.2/firebase-firestore.js"; // Import Firestore functions
import "./booking.css";
const BookingPage = () => {
  const [userId, setUserId] = useState(null);
  const [purchasedCourses, setPurchasedCourses] = useState([]);

  // Function to get the value of a specific cookie by name
  const getCookie = (name) => {
    const value = `; ${document.cookie}`;
    const parts = value.split(`; ${name}=`);
    if (parts.length === 2) return parts.pop().split(';').shift();
    return null;
  };

  useEffect(() => {
    // Check if user is logged in by looking for userId in cookies
    const currentUser = getCookie("userId");

    if (currentUser) {
      setUserId(currentUser);

      // Fetch user data from Firestore
      const fetchUserData = async () => {
        try {
          const userRef = doc(db, "users", currentUser);
          const userDoc = await getDoc(userRef);

          if (userDoc.exists()) {
            const userData = userDoc.data();
            setPurchasedCourses(userData.purchasedCourses || []);
          } else {
            console.log("User document not found in Firestore.");
          }
        } catch (error) {
          console.error("Error fetching user data:", error);
        }
      };

      fetchUserData();
    } else {
      console.log("No user logged in.");
    }
  }, []); // Runs once when the component mounts

  // Function to check if the course has already been purchased
  const isCoursePurchased = (courseName) => {
    return purchasedCourses.includes(courseName);
  };

  return (
    <main id="main">
      <div className="breadcrumbs" data-aos="fade-in">
        <div className="container">
          <h2>Course Booking</h2>
          <p>Book your courses now!</p>
        </div>
      </div>

      <section id="booking" className="booking">
        <div className="container" data-aos="fade-up">
          <div className="row">
            {purchasedCourses.length > 0 ? (
              purchasedCourses.map((course, index) => (
                <div className="col-lg-3 col-md-6 mt-4" key={index}>
                  <div className="course-card">
                    <div className="course-card-body">
                      <h3>{course}</h3>
                      <h4>
                        <sup>Rs</sup>400<span> / hr</span>
                      </h4>
                      <ul>
                        <li>Available on Saturdays, Sundays</li>
                        <li>9:00 AM TO 5:00 PM</li>
                      </ul>
                      <div className="course-status">
                        {isCoursePurchased(course) ? (
                          <span className="status booked">Booked</span>
                        ) : (
                          <span className="status available">Available for Booking</span>
                        )}
                      </div>
                    </div>
                  </div>
                </div>
              ))
            ) : (
              <p>No purchased courses available for booking. Please purchase courses first.</p>
            )}
          </div>
        </div>
      </section>
    </main>
  );
};

export default BookingPage;
