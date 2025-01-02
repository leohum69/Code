import React from 'react';
import { Route, Routes, useLocation } from 'react-router-dom';
import Header from './Header';
import Home from './Home';
import Courses from './Courses';
import Trainers from './Trainers';
import Blog from './Blog';
import Pricing from './Pricing';
import Features from './Features';
import Feedback from './Feedback';
import Resources from './Resources';
import Booking from './Booking';
import Conversation from './Conversation';
import Notification from './Notification';
import Contact from './Contact';
import Login from './Login';

function App() {
  const location = useLocation();

  console.log('Current location:', location.pathname); // Debugging step to check the path

  return (
    <>
      {/* Conditionally render the Header if not on the login page */}
      {location.pathname !== '/' && <Header />}

      <Routes>
        {/* Define the login route explicitly */}
        <Route path="/" element={<Login />} />

        {/* Other routes */}
        <Route path="/home" element={<Home />} />
        <Route path="/courses" element={<Courses />} />
        <Route path="/trainers" element={<Trainers />} />
        <Route path="/blog" element={<Blog />} />
        <Route path="/pricing" element={<Pricing />} />
        <Route path="/features" element={<Features />} />
        <Route path="/feedback" element={<Feedback />} />
        <Route path="/resources" element={<Resources />} />
        <Route path="/booking" element={<Booking />} />
        <Route path="/conversation" element={<Conversation />} />
        <Route path="/notification" element={<Notification />} />
        <Route path="/contact" element={<Contact />} />
      </Routes>
    </>
  );
}

export default App;
