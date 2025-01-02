import React from 'react';
import Header from './Header';


const TrainersPage = () => {

  <Header />
  return (
    <main id="main" data-aos="fade-in">

      {/* ======= Breadcrumbs ======= */}
      <div className="breadcrumbs">
        <div className="container">
          <h2>Trainers</h2>
          <p>We've the best senior students as your mentor who secured A+ in that specific subject course and teach you in the best way and help you to Ace your academic grades.</p>
        </div>
      </div>{/* End Breadcrumbs */}

      {/* ======= Trainers Section ======= */}
      <section id="trainers" className="trainers">
        <div className="container" data-aos="fade-up">

          <div className="row" data-aos="zoom-in" data-aos-delay="100">
            <div className="col-lg-4 col-md-6 d-flex align-items-stretch">
              <div className="member">
                <img src="assets/img/trainers/trainer-1.jpg" className="img-fluid" alt="" />
                <div className="member-content">
                  <h4>John Stringer</h4>
                  <span>Software Developer</span>
                  <p>Meet him, the guy who secured Gold Medal from his last 3 Semesters and done many software projects as a part-time freelancer. He also secured A+ grade in his course subject of Fundamentals of Software Engineering.</p>
                </div>
              </div>
            </div>

            <div className="col-lg-4 col-md-6 d-flex align-items-stretch">
              <div className="member">
                <img src="assets/img/trainers/trainer-2.jpg" className="img-fluid" alt="" />
                <div className="member-content">
                  <h4>Sarah</h4>
                  <span>Digital Marketing</span>
                  <p>Learn your Elective Subject of Facebook Digital Marketing from Sarah, who not only secured A+ Grade in his academic but also earning from Digital Marketing and could provide you best tips for both earning and from the academic perspective.</p>
                </div>
              </div>
            </div>

            <div className="col-lg-4 col-md-6 d-flex align-items-stretch">
              <div className="member">
                <img src="assets/img/trainers/trainer-3.jpg" className="img-fluid" alt="" />
                <div className="member-content">
                  <h4>William Anderson</h4>
                  <span>Programming</span>
                  <p>The best course from the best person. Meet William who is the Coding Master and won many university competitions and also secured A+ Grades throughout his programming subject and from him you can get valuable tips to speed up your programming skills.</p>
                </div>
              </div>
            </div>
          </div>

        </div>
      </section>{/* End Trainers Section */}

    </main>
  );
};

export default TrainersPage;
