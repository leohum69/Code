// import React, { useState } from 'react';
// import Axios from 'axios';
// import './App.css';

// function App() {

//   const [name, setName] = useState('');
//   const [phone, setPhone] = useState('');

//   const addNewNumber = () => {
//     Axios.post('http://localhost:8080/add-phone', { name, phone });
//   }

//   return (
//     <div className="container">
//       <label htmlFor="">Name: </label>
//       <input type="text" onChange={(e) => setName(e.target.value)} /><br /><br />
      
//       <label htmlFor="">Phone: </label>
//       <input type="number" onChange={(e) => setPhone(e.target.value)} /><br /><br />

//       <button onClick={addNewNumber}>Add New Number</button>
//     </div> 
//   );
// }

// export default App;



//getphone


// import React, { useState, useEffect } from 'react';
// import Axios from 'axios';
// import './App.css';

// function App() {

//   const [phonebook, setPhonebook] = useState([]);

//   useEffect(() => {
//     Axios.get('http://localhost:8080/get-phone')
//       .then(res => {
//         if (res.data && res.data.data && res.data.data.phoneNumbers) {
//           setPhonebook(res.data.data.phoneNumbers);
//         } else {
//           console.error("Unexpected response structure:", res.data);
//         }
//       })
//       .catch(error => {
//         console.error("Error fetching phonebook:", error);
//       });
//   }, []);

//   return (
//     <div className="container">
//       <h1>PhoneBook List</h1>
//       {
//         phonebook.map((val, index) => (
//           <div key={val.id || index} className="phone">
//             <h1>{val.name}</h1>
//             <h1>{val.phone}</h1>
//           </div>
//         ))
//       }
//     </div>
//   );
// }

// export default App;

//update

// import React, { useState } from 'react';
// import Axios from 'axios';
// import './App.css';

// function App() {
//   const [id, setId] = useState('');
//   const [newName, setNewName] = useState('');
//   const [newPhone, setNewPhone] = useState('');

//   const updatePhoneBook = () => {
//     // Ensure `id` is part of the URL path
//     Axios.patch(`http://localhost:8080/update-phone/${id}`, { name: newName, phone: newPhone })
//       .then(response => {
//         console.log("Update successful:", response.data);
//       })
//       .catch(error => {
//         console.error("Error updating phonebook:", error);
//       });
//   };

//   return (
//     <div className="container">
//       <h1>Update PhoneBook Entry</h1>

//       <label>ID: </label>
//       <input 
//         type="text" 
//         placeholder="Enter ID..." 
//         onChange={(e) => setId(e.target.value)} 
//         value={id}
//       />
      
//       <label>Name: </label>
//       <input 
//         type="text" 
//         placeholder="Update Name..." 
//         onChange={(e) => setNewName(e.target.value)} 
//         value={newName}
//       />

//       <label>Phone: </label>
//       <input 
//         type="number" 
//         placeholder="Update Phone..." 
//         onChange={(e) => setNewPhone(e.target.value)} 
//         value={newPhone}
//       />

//       <button 
//         className="update-btn"  
//         onClick={updatePhoneBook}
//       >
//         Update
//       </button>
//     </div>
//   );
// }

// export default App;




//delete

// import React, { useState, useEffect } from 'react';
// import Axios from 'axios';
// import './App.css';

// function App() {
//   const [phonebook, setPhonebook] = useState([]);
//   const [newPhone, setNewPhone] = useState(0);

//   // Fetch phonebook data on component mount
//   useEffect(() => {
//     Axios.get('http://localhost:8080/get-phone')
//       .then((res) => {
//         if (res.data && res.data.data && res.data.data.phoneNumbers) {
//           setPhonebook(res.data.data.phoneNumbers);
//         }
//       })
//       .catch((error) => {
//         console.error("Error fetching phonebook:", error);
//       });
//   }, []);

//   // Update phone number
//   const updatePhone = (id) => {
//     Axios.patch(`http://localhost:8080/update-phone/${id}`, { phone: newPhone })
//       .then((response) => {
//         setPhonebook(phonebook.map((entry) => 
//           entry._id === id ? { ...entry, phone: newPhone } : entry
//         ));
//       })
//       .catch((error) => {
//         console.error("Error updating phone number:", error);
//       });
//   };

//   // Delete phone entry
//   const deletePhone = (id) => {
//     Axios.delete(`http://localhost:8080/delete-phone/${id}`)
//       .then(() => {
//         setPhonebook(phonebook.filter((entry) => entry._id !== id));
//       })
//       .catch((error) => {
//         console.error("Error deleting phone entry:", error);
//       });
//   };

//   return (
//     <div className="container">
//       <h1>PhoneBook List</h1>
//       {phonebook.map((val, key) => (
//         <div key={val._id || key} className="phone">
//           <h1>{val.name}</h1>
//           <h1>{val.phone}</h1>
//           <input 
//             type="number" 
//             placeholder="Update Phone..." 
//             onChange={(e) => setNewPhone(e.target.value)} 
//           />
//           <button className="update-btn" onClick={() => updatePhone(val._id)}>
//             Update
//           </button>
//           <button className="delete-btn" onClick={() => deletePhone(val._id)}>
//             Delete
//           </button>
//         </div>
//       ))}
//     </div>
//   );
// }

// export default App;


// src/App.js
import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Home from './pages/Home';
import PhoneBook from './pages/PhoneBook';
import AddPhone from './components/AddPhone';
//import "./app.css"

function App() {
  return (
    <Router>
      <div className="container">
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/add" element={<AddPhone />} />
          <Route path="/phonebook" element={<PhoneBook />} />
        </Routes>
      </div>
    </Router>
  );
}

export default App;
