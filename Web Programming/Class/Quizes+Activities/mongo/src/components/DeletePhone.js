// src/components/DeletePhone.js
import React from 'react';
import Axios from 'axios';

function DeletePhone({ id, onDelete }) {
  const deletePhone = () => {
    Axios.delete(`http://localhost:8080/delete-phone/${id}`)
      .then(() => onDelete(id))
      .catch((error) => {
        console.error("Error deleting phone entry:", error);
      });
  };

  return <button onClick={deletePhone}>Delete</button>;
}

export default DeletePhone;
