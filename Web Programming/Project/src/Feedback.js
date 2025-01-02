import React from 'react';
import Header from './Header';

const TrainersFeedbackPage = () => {
<Header />
  const submitReview = (teacherId) => {
    const comment = document.querySelector(`#comment-${teacherId}`).value;
    const stars = document.querySelector(`#stars-${teacherId}`).value;

    const reviewElement = document.createElement('div');
    reviewElement.classList.add('review');
    reviewElement.innerHTML = `
      <p><strong>Rating: ${stars}/5</strong></p>
      <p>${comment}</p>
    `;

    const reviewsContainer = document.querySelector(`#reviews-${teacherId}`);
    reviewsContainer.appendChild(reviewElement);
    
  }

  return (
    <main id="main" data-aos="fade-in">
      {/* ======= Breadcrumbs ======= */}
      <div className="breadcrumbs">
        <div className="container">
          <h2>Trainers Feedback</h2>
          <p>We've the best senior students as your mentor who secured A+ in that specific subject course and teach you in the best way and help you to Ace your academic grades. </p>
        </div>
      </div>{/* End Breadcrumbs */}

      {/* ======= Trainers Section ======= */}
      <section id="trainers" className="trainers">
        <div className="container" data-aos="fade-up">
          <div className="row" data-aos="zoom-in" data-aos-delay="100">
            {/* Teacher 1 */}
            <div className="col-lg-4 col-md-6 d-flex align-items-stretch">
              <div className="member">
                {/* Image */}
                <img src="assets/img/trainers/trainer-1.jpg" className="img-fluid" alt="" />
                {/* Teacher Info */}
                <div className="member-content">
                  <h4>John Stringer</h4>
                  <span>Software Developer</span>
                  {/* Teacher Feedback */}
                  <p>
                    John is an exceptional mentor, showcasing excellence by securing Gold Medals in the last 3 semesters. His practical experience in software projects as a freelancer, coupled with an A+ grade in Fundamentals of Software Engineering, offers invaluable insights to students.
                  </p>
                  {/* Feedback Form */}
                  <form id="form-1">
                    <div className="form-group">
                      <label htmlFor="comment-1">Add your comment:</label>
                      <textarea className="form-control" id="comment-1" rows="3"></textarea>
                    </div>
                    <div className="form-group">
                      <label htmlFor="stars-1">Rate the teacher:</label>
                      <select className="form-control" id="stars-1">
                        <option value="1">1 star</option>
                        <option value="2">2 stars</option>
                        <option value="3">3 stars</option>
                        <option value="4">4 stars</option>
                        <option value="5">5 stars</option>
                      </select>
                    </div>
                    <button type="button" className="btn btn-primary" onClick={() => submitReview(1)}>Submit</button>
                  </form>
                  {/* Student Reviews */}
                  <div className="student-reviews" id="reviews-1"></div>
                  {/* Social Links */}
                  <div className="social">
                    <a href=""><i className="bi bi-twitter"></i></a>
                    <a href=""><i className="bi bi-facebook"></i></a>
                    <a href=""><i className="bi bi-instagram"></i></a>
                    <a href=""><i className="bi bi-linkedin"></i></a>
                  </div>
                </div>
              </div>
            </div>
            {/* Repeat for other teachers */}
          </div>
        </div>
      </section>{/* End Trainers Section */}
    </main>
  );
};

export default TrainersFeedbackPage;
