import React from 'react';
import Header from './Header';


function Courses() {
  return (
    <div>
      <Header />
      <main id="main" data-aos="fade-in">
        <div className="breadcrumbs">
          <div className="container">
            <h2>Courses</h2>
            <p>Unlocking wisdom Step by Step</p>
          </div>
        </div>
        <section id="courses" className="courses">
          <div className="container" data-aos="fade-up">
            <div className="row" data-aos="zoom-in" data-aos-delay="100">
              <div className="col-lg-4 col-md-6 d-flex align-items-stretch">
                <div className="course-item">
                  <img src="assets/img/course-1.jpg" className="img-fluid" alt="..." />
                  <div className="course-content">
                    <div className="d-flex justify-content-between align-items-center mb-3">
                      <h4>Software Development</h4>
                      <p className="price">400 Rs/hr</p>
                    </div>
                    <h3><a href="course-details.html">Fundamentals Of Software Engineering</a></h3>
                    <p>Learn Software Enginnering Fundamentals from the best Seniors who secured A+ Grades and get tips from them to Ace your Software Skills.</p>
                    <div className="trainer d-flex justify-content-between align-items-center">
                      <div className="trainer-profile d-flex align-items-center">
                        <img src="assets/img/trainers/trainer-1.jpg" className="img-fluid" alt="" />
                        <span>John Stringer</span>
                      </div>
                      <div className="trainer-rank d-flex align-items-center">
                        <i className="bx bx-user"></i>&nbsp;3
                        &nbsp;&nbsp;
                        <i className="bx bx-heart"></i>&nbsp;7
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="col-lg-4 col-md-6 d-flex align-items-stretch mt-4 mt-md-0">
                <div className="course-item">
                  <img src="assets/img/course-2.jpg" className="img-fluid" alt="..." />
                  <div className="course-content">
                    <div className="d-flex justify-content-between align-items-center mb-3">
                      <h4>Digital Marketing </h4>
                      <p className="price">350 Rs/hr</p>
                    </div>
                    <h3><a href="course-details.html">Facebook Digital Marketing</a></h3>
                    <p>Get to learn the best demanding skill of Facebook Digital Marketing from the best students who are also earning from it.</p>
                    <div className="trainer d-flex justify-content-between align-items-center">
                      <div className="trainer-profile d-flex align-items-center">
                        <img src="assets/img/trainers/trainer-2.jpg" className="img-fluid" alt="" />
                        <span>Sarah</span>
                      </div>
                      <div className="trainer-rank d-flex align-items-center">
                        <i className="bx bx-user"></i>&nbsp;4
                        &nbsp;&nbsp;
                        <i className="bx bx-heart"></i>&nbsp;2
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="col-lg-4 col-md-6 d-flex align-items-stretch mt-4 mt-lg-0">
                <div className="course-item">
                  <img src="assets/img/course-3.jpg" className="img-fluid" alt="..." />
                  <div className="course-content">
                    <div className="d-flex justify-content-between align-items-center mb-3">
                      <h4>Programming</h4>
                      <p className="price">450 Rs/hr</p>
                    </div>
                    <h3><a href="course-details.html">Python, C++ , JavaScript and more..</a></h3>
                    <p>Learn the most demanding Programming course of our from the best Coders of University.</p>
                    <div className="trainer d-flex justify-content-between align-items-center">
                      <div className="trainer-profile d-flex align-items-center">
                        <img src="assets/img/trainers/trainer-3.jpg" className="img-fluid" alt="" />
                        <span>William Anderson</span>
                      </div>
                      <div className="trainer-rank d-flex align-items-center">
                        <i className="bx bx-user"></i>&nbsp;8
                        &nbsp;&nbsp;
                        <i className="bx bx-heart"></i>&nbsp;7
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </section>
      </main>
      <div id="preloader"></div>
      <a href="#" className="back-to-top d-flex align-items-center justify-content-center"><i className="bi bi-arrow-up-short"></i></a>
      <script src="assets/vendor/purecounter/purecounter_vanilla.js"></script>
      <script src="assets/vendor/aos/aos.js"></script>
      <script src="assets/vendor/bootstrap/js/bootstrap.bundle.min.js"></script>
      <script src="assets/vendor/swiper/swiper-bundle.min.js"></script>
      <script src="assets/vendor/php-email-form/validate.js"></script>
      <script src="assets/js/main.js"></script>
    </div>
  );
}

export default Courses;
