// src/pages/Home.js
import React from 'react';
import { Link } from 'react-router-dom';

function Home() {
  return (
    <div>
      <h1>Phone Book Application</h1>
      <Link to="/add">Add New Phone</Link>
      <Link to="/phonebook">View Phone Book</Link>
    </div>
  );
}

export default Home;
