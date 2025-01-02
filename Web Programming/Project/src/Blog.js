import React from 'react';
import Header from './Header';

function Blog() {
  return (

    <div>
      <Header />
      <main id="main">
        <div className="breadcrumbs" data-aos="fade-in">
          <div className="container">
            <h2>Blog Section</h2>
            <p>Get up to date through Blogs from your mentors regarding study and get tips which will help you in your academics.</p>
          </div>
        </div>
        <section id="events" className="events">
          <div className="container" data-aos="fade-up">
            <div className="row">
              <div className="col-md-6 d-flex align-items-stretch">
                <div className="card">
                  <div className="card-img">
                    <img src="assets/img/events-1.jpg" alt="..." />
                  </div>
                  <div className="card-body">
                    <h5 className="card-title"><a href="">Introduction to Software Engineering</a></h5>
                    <p className="fst-italic text-center">Sunday, September 26th at 7:00 pm</p>
                    <p className="card-text">Get to learn the insightful content from your mentor John Stringer how actually Software Development helps you to get your first project.</p>
                  </div>
                </div>
              </div>
              <div className="col-md-6 d-flex align-items-stretch">
                <div className="card">
                  <div className="card-img">
                    <img src="assets/img/events-2.jpg" alt="..." />
                  </div>
                  <div className="card-body">
                    <h5 className="card-title"><a href="">Digital Marketing Strategies</a></h5>
                    <p className="fst-italic text-center">Sunday, November 15th at 7:00 pm</p>
                    <p className="card-text">Aware yourself with the best Marketing Stratagies to up scale yours skills as well as your academics to get high scores. It also helps you and guide you how to start your Business through Digital Marketing.</p>
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

export default Blog;
