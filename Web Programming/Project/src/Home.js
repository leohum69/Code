import React, { useEffect } from 'react';
import Header from './Header';
import { initializeApp } from "https://www.gstatic.com/firebasejs/11.0.2/firebase-app.js";
import {
  getFirestore,
  collection,
  addDoc,
} from "https://www.gstatic.com/firebasejs/11.0.2/firebase-firestore.js";

// Your web app's Firebase configuration
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

function Home() {
  useEffect(() => {
    const form = document.getElementById('subscribeForm');
    form.addEventListener('submit', async (e) => {
      e.preventDefault();
      const email = e.target.email.value;

      try {
        await addDoc(collection(db, 'subscribers'), { email });
        alert('Subscribed successfully!');
      } catch (error) {
        console.error('Error adding document: ', error);
        alert('Failed to subscribe. Please try again.');
      }

      e.target.reset();
    });
  }, []);

  return (
    <React.Fragment>
      <Header />
      <main id="main">
        <body>
          {/* Hero Section */}
          <section id="hero" className="d-flex justify-content-center align-items-center">
            <div className="container position-relative" data-aos="zoom-in" data-aos-delay="100">
              <h1><br />PeerLearn Hub</h1>
              <h2>Empowering Education Together</h2>
              <a href="courses" className="btn-get-started">Get Started</a>
            </div>
          </section>
          {/* End Hero */}

          <main id="main">
            {/* About Section */}
            <section id="about" className="about">
              <div className="container" data-aos="fade-up">
                <div className="row">
                  <div className="col-lg-6 order-1 order-lg-2" data-aos="fade-left" data-aos-delay="100">
                    <img src="assets/img/about.jpg" className="img-fluid" alt="" />
                  </div>
                  <div className="col-lg-6 pt-4 pt-lg-0 order-2 order-lg-1 content">
                    <h3>Our Platform Provides :</h3>
                    <p className="fst-italic">
                      Modern education faces challenges such as comprehension issues, financial obstacles for talented students, and a lack of practical experience for future educators so we're providing them a platform to earn.
                    </p>
                    <ul>
                      <li><i className="bi bi-check-circle"></i>Peer-to-peer learning</li>
                      <li><i className="bi bi-check-circle"></i>Tutoring platform</li>
                      <li><i className="bi bi-check-circle"></i>Financial support for exceptional students</li>
                    </ul>
                    <p>
                      So, if you're a student and struggling in courses we help you to get the best knowledge from your seniors and if you're struggling financially or want to taste teaching experience as a senior we'll help you with that :)
                    </p>
                  </div>
                </div>
              </div>
            </section>
            {/* End About Section */}

            {/* Counts Section */}
            <section id="counts" className="counts section-bg">
              <div className="container">
                <div className="row counters">
                  <div className="col-lg-3 col-6 text-center">
                    <span data-purecounter-start="0" data-purecounter-end="9" data-purecounter-duration="1" className="purecounter"></span>
                    <p>Students</p>
                  </div>
                  <div className="col-lg-3 col-6 text-center">
                    <span data-purecounter-start="0" data-purecounter-end="5" data-purecounter-duration="1" className="purecounter"></span>
                    <p>Courses</p>
                  </div>
                  <div className="col-lg-3 col-6 text-center">
                    <span data-purecounter-start="0" data-purecounter-end="2" data-purecounter-duration="1" className="purecounter"></span>
                    <p>Events</p>
                  </div>
                  <div className="col-lg-3 col-6 text-center">
                    <span data-purecounter-start="0" data-purecounter-end="3" data-purecounter-duration="1" className="purecounter"></span>
                    <p>Trainers</p>
                  </div>
                </div>
              </div>
            </section>
            {/* End Counts Section */}

            {/* Why Us Section */}
            <section id="why-us" className="why-us">
              <div className="container" data-aos="fade-up">
                <div className="row">
                  <div className="col-lg-4 d-flex align-items-stretch">
                    <div className="content">
                      <h3>Why Choose Senior Mentor?</h3>
                      <p>
                        Choosing a senior student as a mentor in university life is a wise decision. Their experience and insights provide invaluable subject knowledge, study tips, and guidance. Seniors understand the academic terrain, offer a fresh perspective, and can help you navigate the challenges of university, enhancing your educational journey.
                      </p>
                      <div className="text-center">
                        <a href="about.js" className="more-btn">Learn More <i className="bx bx-chevron-right"></i></a>
                      </div>
                    </div>
                  </div>
                  <div className="col-lg-8 d-flex align-items-stretch" data-aos="zoom-in" data-aos-delay="100">
                    <div className="icon-boxes d-flex flex-column justify-content-center">
                      <div className="row">
                        <div className="col-xl-4 d-flex align-items-stretch">
                          <div className="icon-box mt-4 mt-xl-0">
                            <i className="bx bx-receipt"></i>
                            <h4>On-Site Coaching</h4>
                            <p>You can take classes from your selected mentor on-site and ask your queries face to face.</p>
                          </div>
                        </div>
                        <div className="col-xl-4 d-flex align-items-stretch">
                          <div className="icon-box mt-4 mt-xl-0">
                            <i className="bx bx-receipt"></i>
                            <h4>DEMO</h4>
                            <p>We are giving demo.</p>
                          </div>
                        </div>
                        <div className="col-xl-4 d-flex align-items-stretch">
                          <div className="icon-box mt-4 mt-xl-0">
                            <i className="bx bx-cube-alt"></i>
                            <h4>Choose Mentor On Your Own</h4>
                            <p>You can choose mentor of your own choice depending on their Ranking and way of teaching.</p>
                          </div>
                        </div>
                        <div className="col-xl-4 d-flex align-items-stretch">
                          <div className="icon-box mt-4 mt-xl-0">
                            <i className="bx bx-images"></i>
                            <h4>Study Helping Material</h4>
                            <p>You'll get helping material from your mentor including Past Papers , Assignments , Quizzes and much more.</p>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </section>
            {/* End Why Us Section */}
          </main>

          {/* Footer */}
          <footer id="footer">
            <div className="footer-top">
              <div className="container">
                <div className="row">
                  <div className="col-lg-3 col-md-6 footer-contact">
                    <h3>PeerLearn Hub</h3>
                    <p>
                      Fast University Islamabad<br />
                      Islamabad , Pakistan<br />
                      <strong>Phone:</strong> +92 316 000000<br />
                      <strong>Email:</strong> info@PeerLearn Hub.com<br />
                    </p>
                  </div>
                  <div className="col-lg-4 col-md-6 footer-newsletter">
                    <h4>Join Our Newsletter to get Daily Blog</h4>
                    <form id="subscribeForm" action="" method="post">
                      <input type="email" name="email" required /><input type="submit" value="Subscribe" />
                    </form>
                  </div>
                </div>
              </div>
            </div>
            <div className="container d-md-flex py-4">
              <div className="me-md-auto text-center text-md-start">
                <div className="copyright">
                  &copy; Copyright <strong><span>PeerLearn Hub</span></strong>. All Rights Reserved
                </div>
                <div className="credits">
                  Designed by <a href="https://bootstrapmade.com/">BootstrapMade</a>
                </div>
              </div>
              <div className="social-links text-center text-md-right pt-3 pt-md-0">
                <a href="#" className="twitter"><i className="bx bxl-twitter"></i></a>
                <a href="#" className="facebook"><i className="bx bxl-facebook"></i></a>
                <a href="#" className="instagram"><i className="bx bxl-instagram"></i></a>
                <a href="#" className="google-plus"><i className="bx bxl-skype"></i></a>
                <a href="#" className="linkedin"><i className="bx bxl-linkedin"></i></a>
              </div>
            </div>
          </footer>
          {/* End Footer */}

          <div id="preloader"></div>
          <a href="#" className="back-to-top d-flex align-items-center justify-content-center"><i className="bi bi-arrow-up-short"></i></a>

          {/* Vendor JS Files */}
          <script src="assets/vendor/purecounter/purecounter_vanilla.js"></script>
          <script src="assets/vendor/aos/aos.js"></script>
          <script src="assets/vendor/bootstrap/js/bootstrap.bundle.min.js"></script>
          <script src="assets/vendor/swiper/swiper-bundle.min.js"></script>
          <script src="assets/vendor/php-email-form/validate.js"></script>

          {/* Template Main JS File */}
          <script src="assets/js/main.js"></script>
        </body>
      </main>
    </React.Fragment>
  );
}

export default Home;

