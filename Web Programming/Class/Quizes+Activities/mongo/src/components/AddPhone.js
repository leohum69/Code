// src/components/AddPhone.js
import React, { useState } from 'react';
import Axios from 'axios';

function AddPhone() {
  const [name, setName] = useState('');
  const [phone, setPhone] = useState('');

  const addNewNumber = () => {
    Axios.post('http://localhost:8080/add-phone', { name, phone });
  };

  return (
    <div>
      <label>Name: </label>
      <input type="text" onChange={(e) => setName(e.target.value)} /><br /><br />

      <label>Phone: </label>
      <input type="number" onChange={(e) => setPhone(e.target.value)} /><br /><br />

      <button onClick={addNewNumber}>Add New Number</button>
    </div>
  );
}

export default AddPhone;
