import React, { useState, useEffect } from "react";
import { db } from "./Auth"; // Assuming Firebase has been initialized in Auth.js
import { doc, getDoc, setDoc } from "https://www.gstatic.com/firebasejs/11.0.2/firebase-firestore.js"; // Import Firestore functions

const PricingPage = () => {
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
          const userRef = doc(db, "users", currentUser); // Correctly accessing Firestore document using doc()
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

  // Function to update purchased courses in Firestore
  const updatePurchasedCourses = async (courseName) => {
    if (!userId) {
      console.log("No user ID found in cookies. Please log in to purchase courses.");
      alert("Please log in to purchase courses.");
      return;
    }

    console.log("User ID found:", userId);

    try {
      // Get the user document from Firestore using the doc() method (instead of db.collection())
      const userRef = doc(db, "users", userId); // Correctly accessing the user's document
      console.log("Attempting to fetch user document from Firestore:", userRef.path);
      const userDoc = await getDoc(userRef);

      if (userDoc.exists()) {
        console.log("User document found in Firestore:", userDoc.data());

        const userData = userDoc.data();
        const currentPurchasedCourses = userData.purchasedCourses || [];

        // Check if the course is already in the list
        if (!currentPurchasedCourses.includes(courseName)) {
          console.log(`Course "${courseName}" not purchased. Adding to purchased courses...`);

          // Add the new course to Firestore
          currentPurchasedCourses.push(courseName);
          await setDoc(userRef, { purchasedCourses: currentPurchasedCourses }, { merge: true });

          // Update the state with the new purchased courses list
          setPurchasedCourses(currentPurchasedCourses);

          alert(`Successfully purchased ${courseName}`);
        } else {
          console.log(`Course "${courseName}" already purchased.`);
          alert("You have already purchased this course.");
        }
      } else {
        console.log("User document does not exist in Firestore.");
        alert("User not found in Firestore.");
      }
    } catch (error) {
      console.error("Error during course purchase:", error);
      alert("An error occurred. Please try again.");
    }
  };

  return (
    <main id="main">
      <div className="breadcrumbs" data-aos="fade-in">
        <div className="container">
          <h2>Pricing</h2>
          <p>We've the best reasonable prices</p>
        </div>
      </div>
  
      <section id="pricing" className="pricing">
        <div className="container" data-aos="fade-up">
          <div className="row">
            {/* Course 1 */}
            <div className="col-lg-3 col-md-6">
              <div className="box">
                <h3>John Stringer</h3>
                <h4>
                  <sup>Rs</sup>400<span> / hr</span>
                </h4>
                <ul>
                  <li>Software Development</li>
                  <li>Available on Saturday, Sunday</li>
                  <li>9:00 AM TO 5:00 PM</li>
                </ul>
                <div className="btn-wrap">
                  {isCoursePurchased("Software Development") ? (
                    <button className="btn-buy purchased" disabled>
                      Already Purchased
                    </button>
                  ) : (
                    <button
                      className="btn-buy"
                      onClick={() => updatePurchasedCourses("Software Development")}
                    >
                      Book Now
                    </button>
                  )}
                </div>
              </div>
            </div>
  
            {/* Course 2 */}
            <div className="col-lg-3 col-md-6 mt-4 mt-md-0">
              <div className="box featured">
                <h3>Sarah</h3>
                <h4>
                  <sup>Rs</sup>350<span> / hr</span>
                </h4>
                <ul>
                  <li>Facebook Digital Marketing</li>
                  <li>Available on Saturday, Sunday</li>
                  <li>9:00 AM TO 5:00 PM</li>
                </ul>
                <div className="btn-wrap">
                  {isCoursePurchased("Facebook Digital Marketing") ? (
                    <button className="btn-buy purchased" disabled>
                      Already Purchased
                    </button>
                  ) : (
                    <button
                      className="btn-buy"
                      onClick={() => updatePurchasedCourses("Facebook Digital Marketing")}
                    >
                      Book Now
                    </button>
                  )}
                </div>
              </div>
            </div>
  
            {/* Course 3 */}
            <div className="col-lg-3 col-md-6 mt-4 mt-lg-0">
              <div className="box">
                <h3>William Anderson</h3>
                <h4>
                  <sup>Rs</sup>450<span> / hr</span>
                </h4>
                <ul>
                  <li>Programming</li>
                  <li>Available on Saturday, Sunday</li>
                  <li>9:00 AM TO 5:00 PM</li>
                </ul>
                <div className="btn-wrap">
                  {isCoursePurchased("Programming") ? (
                    <button className="btn-buy purchased" disabled>
                      Already Purchased
                    </button>
                  ) : (
                    <button
                      className="btn-buy"
                      onClick={() => updatePurchasedCourses("Programming")}
                    >
                      Book Now
                    </button>
                  )}
                </div>
              </div>
            </div>
  
            {/* Course 4 */}
            <div className="col-lg-3 col-md-6 mt-4 mt-lg-0">
              <div className="box">
                <h3>Olivia Williams</h3>
                <h4>
                  <sup>Rs</sup>380<span> / hr</span>
                </h4>
                <ul>
                  <li>Graphic Design</li>
                  <li>Available on Wednesday, Friday</li>
                  <li>9:00 AM TO 5:00 PM</li>
                </ul>
                <div className="btn-wrap">
                  {isCoursePurchased("Graphic Design") ? (
                    <button className="btn-buy purchased" disabled>
                      Already Purchased
                    </button>
                  ) : (
                    <button
                      className="btn-buy"
                      onClick={() => updatePurchasedCourses("Graphic Design")}
                    >
                      Book Now
                    </button>
                  )}
                </div>
              </div>
            </div>
  
            {/* Course 5 */}
            <div className="col-lg-3 col-md-6 mt-4 mt-lg-0">
              <div className="box">
                <h3>James Roberts</h3>
                <h4>
                  <sup>Rs</sup>500<span> / hr</span>
                </h4>
                <ul>
                  <li>Data Science</li>
                  <li>Available on Monday, Thursday</li>
                  <li>9:00 AM TO 5:00 PM</li>
                </ul>
                <div className="btn-wrap">
                  {isCoursePurchased("Data Science") ? (
                    <button className="btn-buy purchased" disabled>
                      Already Purchased
                    </button>
                  ) : (
                    <button
                      className="btn-buy"
                      onClick={() => updatePurchasedCourses("Data Science")}
                    >
                      Book Now
                    </button>
                  )}
                </div>
              </div>
            </div>
  
            {/* Course 6 */}
            <div className="col-lg-3 col-md-6 mt-4 mt-lg-0">
              <div className="box">
                <h3>Alice White</h3>
                <h4>
                  <sup>Rs</sup>400<span> / hr</span>
                </h4>
                <ul>
                  <li>SEO Optimization</li>
                  <li>Available on Tuesday, Thursday</li>
                  <li>9:00 AM TO 5:00 PM</li>
                </ul>
                <div className="btn-wrap">
                  {isCoursePurchased("SEO Optimization") ? (
                    <button className="btn-buy purchased" disabled>
                      Already Purchased
                    </button>
                  ) : (
                    <button
                      className="btn-buy"
                      onClick={() => updatePurchasedCourses("SEO Optimization")}
                    >
                      Book Now
                    </button>
                  )}
                </div>
              </div>
            </div>
  
          </div>
        </div>
      </section>
    </main>
  );
};

export default PricingPage;
