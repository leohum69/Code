import React, { useState, useEffect } from 'react';
import { db } from './Auth'; // Assuming Firebase is initialized in Auth.js
import { doc, getDoc } from 'https://www.gstatic.com/firebasejs/11.0.2/firebase-firestore.js'; // Import Firestore functions
import Header from './Header';
import './noti.css';

const UpcomingClassesPage = () => {
  const [courses, setCourses] = useState([]);
  const [classSchedules, setClassSchedules] = useState([]);
  const [isClassTime, setIsClassTime] = useState(false);

  // Function to get the value of a specific cookie by name
  const getCookie = (name) => {
    const value = `; ${document.cookie}`;
    const parts = value.split(`; ${name}=`);
    if (parts.length === 2) return parts.pop().split(';').shift();
    return null;
  };

  useEffect(() => {
    const currentUser = getCookie('userId');
    if (currentUser) {
      // Fetch purchased courses for the user
      const fetchCourses = async () => {
        try {
          const userRef = doc(db, 'users', currentUser);
          const userDoc = await getDoc(userRef);

          if (userDoc.exists()) {
            const userData = userDoc.data();
            const purchasedCourses = userData.purchasedCourses || [];
            setCourses(purchasedCourses);
            generateClassSchedules(purchasedCourses);
          } else {
            console.log('User document not found in Firestore.');
          }
        } catch (error) {
          console.error('Error fetching user data:', error);
        }
      };

      fetchCourses();
    } else {
      console.log('No user logged in.');
    }
  }, []);

  // Generate random class schedules for each course
  const generateClassSchedules = (courses) => {
    const classSchedule = courses.map((course) => {
      const randomHour = Math.floor(Math.random() * (17 - 9 + 1)) + 9; // Random hour between 9 AM and 5 PM
      const randomMinute = Math.floor(Math.random() * 60); // Random minute
      const startTime = `${randomHour}:${randomMinute < 10 ? '0' + randomMinute : randomMinute}`;

      return { courseName: course, startTime };
    });
    setClassSchedules(classSchedule);
  };

  useEffect(() => {
    const checkClassTime = () => {
      const now = new Date();
      const dayOfWeek = now.getDay();
      const hour = now.getHours();
      return dayOfWeek === 6 && hour >= 9 && hour < 17; // Check if it's between 9 AM and 5 PM on Saturday
    };

    const interval = setInterval(() => {
      if (checkClassTime()) {
        setIsClassTime(true);
      } else {
        setIsClassTime(false);
      }
    }, 1000);

    return () => clearInterval(interval);
  }, []);

  return (
    <div className="notification-page">
      <Header />
      <div className="notification">
        <h2>Upcoming Classes</h2>
        <div className="class-list">
          {classSchedules.length > 0 ? (
            classSchedules.map((classItem, index) => (
              <div className="class-item" key={index}>
                <h3>Course: {classItem.courseName}</h3>
                <p>Start Time: {classItem.startTime}</p>
              </div>
            ))
          ) : (
            <p>No classes scheduled.</p>
          )}
        </div>
        {isClassTime ? (
          <p className="status available">Class is ongoing! Book your spot now!</p>
        ) : (
          <p className="status no-class">No classes currently scheduled.</p>
        )}
      </div>
    </div>
  );
};

export default UpcomingClassesPage;
