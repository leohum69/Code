// src/components/UpdatePhone.js
import React, { useState } from 'react';
import Axios from 'axios';

function UpdatePhone({ id, name, phone }) {
  const [newPhone, setNewPhone] = useState(phone);

  const updatePhone = () => {
    Axios.patch(`http://localhost:8080/update-phone/${id}`, { phone: newPhone })
      .catch((error) => {
        console.error("Error updating phone number:", error);
      });
  };

  return (
    <div>
      <input
        type="number"
        placeholder="Update Phone..."
        value={newPhone}
        onChange={(e) => setNewPhone(e.target.value)}
      />
      <button onClick={updatePhone}>Update</button>
    </div>
  );
}

export default UpdatePhone;
