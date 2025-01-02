// import React, { useState } from 'react';
// import Header from './Header';


// <Header />
// const ContactPage = () => {
//   const [formData, setFormData] = useState({
//     name: '',
//     university: '',
//     teachingSubject: '',
//     subjectGPA: '',
//     hobbies: '',
//     achievements: '',
//     aboutYourself: ''
//   });

//   const handleChange = (e) => {
//     setFormData({
//       ...formData,
//       [e.target.name]: e.target.value
//     });
//   };

//   const saveApplication = () => {
//     const { name, university, teachingSubject, subjectGPA, hobbies, achievements, aboutYourself } = formData;
//     const textContent = `Name: ${name}\nUniversity: ${university}\nTeaching Subject: ${teachingSubject}\nSubject GPA: ${subjectGPA}\nHobbies: ${hobbies}\nAchievements: ${achievements}\nAbout Yourself: ${aboutYourself}`;
    
//     const blob = new Blob([textContent], { type: 'text/plain' });
//     const url = URL.createObjectURL(blob);
//     const link = document.createElement('a');
//     link.href = url;
//     link.download = 'contact_form_data.txt';
//     document.body.appendChild(link);
//     link.click();
//     document.body.removeChild(link);
//     URL.revokeObjectURL(url);
//   };

//   return (
//     <div>
//       {/* Header */}
//       <header id="header" className="fixed-top">
//         {/* Header content */}
//       </header>

//       {/* Main */}
//       <main id="main">
//         {/* Breadcrumbs */}
//         <div className="breadcrumbs" data-aos="fade-in">
//           {/* Breadcrumbs content */}
//         </div>

//         {/* Contact Section with the Tutor Application Form */}
//         <section id="contact" className="contact">
//           <div className="container" data-aos="fade-up">
//             <div className="row mt-5">
//               <div className="col-lg-8 mt-5 mt-lg-0">
//                 <form className="php-email-form">
//                   <div className="row">
//                     <div className="col-md-6 form-group">
//                       <input type="text" name="name" className="form-control" placeholder="Your Name" onChange={handleChange} required />
//                     </div>
//                     <div className="col-md-6 form-group mt-3 mt-md-0">
//                       <input type="text" name="university" className="form-control" placeholder="University" onChange={handleChange} required />
//                     </div>
//                   </div>
//                   <div className="form-group mt-3">
//                     <input type="text" name="teachingSubject" className="form-control" placeholder="Teaching Subject" onChange={handleChange} required />
//                   </div>
//                   <div className="form-group mt-3">
//                     <input type="text" name="subjectGPA" className="form-control" placeholder="Subject GPA" onChange={handleChange} required />
//                   </div>
//                   <div className="form-group mt-3">
//                     <input type="text" name="hobbies" className="form-control" placeholder="Hobbies" onChange={handleChange} required />
//                   </div>
//                   <div className="form-group mt-3">
//                     <textarea name="achievements" className="form-control" rows="5" placeholder="Achievements" onChange={handleChange} required></textarea>
//                   </div>
//                   <div className="form-group mt-3">
//                     <textarea name="aboutYourself" className="form-control" rows="5" placeholder="About Yourself" onChange={handleChange} required></textarea>
//                   </div>
//                   <div className="text-center">
//                     <button type="button" onClick={saveApplication}>Submit Application</button>
//                   </div>
//                 </form>
//               </div>
//             </div>
//           </div>
//         </section>
//       </main>

//       {/* Footer */}
//       <footer id="footer">
//         {/* Footer content */}
//       </footer>
//     </div>
//   );
// }

// export default ContactPage;



import React, { useState } from 'react';
import Header from './Header';
import { initializeApp } from "https://www.gstatic.com/firebasejs/11.0.2/firebase-app.js";
import {
  getFirestore,
  collection,
  addDoc,
} from "https://www.gstatic.com/firebasejs/11.0.2/firebase-firestore.js";

// Your Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyBjH7hccRE0B9i4qMAFHYNTEcAImYlq30g",
  authDomain: "project-5a928.firebaseapp.com",
  projectId: "project-5a928",
  storageBucket: "project-5a928.firebasestorage.app",
  messagingSenderId: "208997622859",
  appId: "1:208997622859:web:7df18da076e16fb0f399ce",
  measurementId: "G-ED63QM4NWP",
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const db = getFirestore(app);

const ContactPage = () => {
  const [formData, setFormData] = useState({
    name: '',
    university: '',
    teachingSubject: '',
    subjectGPA: '',
    hobbies: '',
    achievements: '',
    aboutYourself: '',
  });

  const handleChange = (e) => {
    setFormData({
      ...formData,
      [e.target.name]: e.target.value,
    });
  };

  const saveApplicationToFirebase = async () => {
    try {
      await addDoc(collection(db, "applications"), formData);
      alert("Application submitted successfully!");
    } catch (error) {
      console.error("Error adding document: ", error);
      alert("Failed to submit the application. Please try again.");
    }
  };

  return (
    <div>
      {/* Header */}
      <header id="header" className="fixed-top">
        {/* Header content */}
      </header>

      {/* Main */}
      <main id="main">
        {/* Breadcrumbs */}
        <div className="breadcrumbs" data-aos="fade-in">
          {/* Breadcrumbs content */}
        </div>

        {/* Contact Section with the Tutor Application Form */}
        <section id="contact" className="contact">
          <div className="container" data-aos="fade-up">
            <div className="row mt-5">
              <div className="col-lg-8 mt-5 mt-lg-0">
                <form className="php-email-form">
                  <div className="row">
                    <div className="col-md-6 form-group">
                      <input
                        type="text"
                        name="name"
                        className="form-control"
                        placeholder="Your Name"
                        onChange={handleChange}
                        required
                      />
                    </div>
                    <div className="col-md-6 form-group mt-3 mt-md-0">
                      <input
                        type="text"
                        name="university"
                        className="form-control"
                        placeholder="University"
                        onChange={handleChange}
                        required
                      />
                    </div>
                  </div>
                  <div className="form-group mt-3">
                    <input
                      type="text"
                      name="teachingSubject"
                      className="form-control"
                      placeholder="Teaching Subject"
                      onChange={handleChange}
                      required
                    />
                  </div>
                  <div className="form-group mt-3">
                    <input
                      type="text"
                      name="subjectGPA"
                      className="form-control"
                      placeholder="Subject GPA"
                      onChange={handleChange}
                      required
                    />
                  </div>
                  <div className="form-group mt-3">
                    <input
                      type="text"
                      name="hobbies"
                      className="form-control"
                      placeholder="Hobbies"
                      onChange={handleChange}
                      required
                    />
                  </div>
                  <div className="form-group mt-3">
                    <textarea
                      name="achievements"
                      className="form-control"
                      rows="5"
                      placeholder="Achievements"
                      onChange={handleChange}
                      required
                    ></textarea>
                  </div>
                  <div className="form-group mt-3">
                    <textarea
                      name="aboutYourself"
                      className="form-control"
                      rows="5"
                      placeholder="About Yourself"
                      onChange={handleChange}
                      required
                    ></textarea>
                  </div>
                  <div className="text-center">
                    <button type="button" onClick={saveApplicationToFirebase}>
                      Submit Application
                    </button>
                  </div>
                </form>
              </div>
            </div>
          </div>
        </section>
      </main>

      {/* Footer */}
      <footer id="footer">
        {/* Footer content */}
      </footer>
    </div>
  );
};

export default ContactPage;
