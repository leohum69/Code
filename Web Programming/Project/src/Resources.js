import React from 'react';
import Header from './Header';

const ContactPage = () => {
  <Header />
  return (
    <main id="main">
      {/* ======= Breadcrumbs ======= */}
      <div className="breadcrumbs" data-aos="fade-in">
        <div className="container">
          <h2>Study Resources</h2>
          <p>Access a wealth of knowledge through online sources. Expand horizons with courses from platforms like Coursera, edX, and MIT OpenCourseWare. Explore diverse subjects, from sciences to humanities, seizing opportunities at your pace. Utilize scholarly platforms like JSTOR, Google Scholar, and Project Gutenberg for in-depth research and learning enrichment.</p>
        </div>
      </div>{/* End Breadcrumbs */}

      <p>Here are some websites to explore for study knowledge and opportunities:</p>

      <ul>
        <li><a href="https://www.coursera.org/for-university">Coursera for Universities</a></li>
        <li><a href="https://www.edx.org/university-courses">edX University Courses</a></li>
        <li><a href="https://ocw.mit.edu/index.htm">MIT OpenCourseWare</a></li>
        <li><a href="https://oyc.yale.edu/">Open Yale Courses</a></li>
        <li><a href="https://www.apple.com/itunes-u/">iTunes U</a></li>
        <li><a href="https://www.jstor.org/">JSTOR</a></li>
        <li><a href="https://scholar.google.com/">Google Scholar</a></li>
        <li><a href="https://academicearth.org/">Academic Earth</a></li>
        <li><a href="https://www.gutenberg.org/">Project Gutenberg</a></li>
        <li><a href="https://online.stanford.edu/">Stanford Online</a></li>
      </ul>
    </main>
  );
};

export default ContactPage;
