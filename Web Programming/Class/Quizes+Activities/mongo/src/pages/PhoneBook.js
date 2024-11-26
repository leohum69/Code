// src/pages/PhoneBook.js
import React, { useState, useEffect } from 'react';
import Axios from 'axios';
import UpdatePhone from '../components/UpdatePhone';
import DeletePhone from '../components/DeletePhone';

function PhoneBook() {
  const [phonebook, setPhonebook] = useState([]);

  useEffect(() => {
    Axios.get('http://localhost:8080/get-phone')
      .then((res) => {
        if (res.data && res.data.data && res.data.data.phoneNumbers) {
          setPhonebook(res.data.data.phoneNumbers);
        }
      })
      .catch((error) => {
        console.error("Error fetching phonebook:", error);
      });
  }, []);

  const handleDelete = (id) => {
    setPhonebook(phonebook.filter((entry) => entry._id !== id));
  };

  return (
    <div>
      <h1>PhoneBook List</h1>
      {phonebook.map((entry) => (
        <div key={entry._id}>
          <h1>{entry.name}</h1>
          <h1>{entry.phone}</h1>
          <UpdatePhone id={entry._id} name={entry.name} phone={entry.phone} />
          <DeletePhone id={entry._id} onDelete={handleDelete} />
        </div>
      ))}
    </div>
  );
}

export default PhoneBook;
