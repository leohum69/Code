import React from 'react';
import { Link } from 'react-router-dom';

function Header() {
  return (
    <header id="header" className="fixed-top">
      <div className="container d-flex align-items-center">
        <h1 className="logo me-auto"><Link to="/">PeerLearn Hub</Link></h1>
        <nav id="navbar" className="navbar order-last order-lg-0">
          <ul>
            <li><Link className="active" to="/">Home</Link></li>
            <li><Link to="/courses">Courses</Link></li>
            <li><Link to="/trainers">Trainers</Link></li>
            <li><Link to="/blog">Blog</Link></li>
            <li><Link to="/pricing">Pricing</Link></li>
            <li className="dropdown">
              <a href="#"><span>Features</span> <i className="bi bi-chevron-down"></i></a>
              <ul>
                <li className="dropdown">
                  <a href="#"><span>Explore More</span> <i className="bi bi-chevron-right"></i></a>
                  <ul>
                    <li><Link to="/feedback">Feedback</Link></li>
                    <li><Link to="/resources">Study Resources</Link></li>
                  </ul>
                </li>
                <li><Link to="/booking">Booking</Link></li>
                <li><Link to="/conversation">Online Chat & Queries</Link></li>
                <li><Link to="/notification">Upcoming Class</Link></li>
              </ul>
            </li>
            <li><Link to="/contact">Contact</Link></li>
            
          </ul>
          <i className="bi bi-list mobile-nav-toggle"></i>
        </nav>
        <Link to="/courses" className="get-started-btn">Get Started</Link>
      </div>
    </header>
  );
}

export default Header;
