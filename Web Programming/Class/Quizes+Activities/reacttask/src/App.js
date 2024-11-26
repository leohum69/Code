import logo from './logo.svg';
import './App.css';
import { createBrowserRouter, RouterProvider } from 'react-router-dom';
import Home from './Home';
import About from './About';
import Contact from './Contact';
import Navbar from './Navbar';
import "./style.css";

function App() {

  const router = createBrowserRouter([
    {
      path: '/', 
      element: <><Navbar /><Home /></>
    },
    {
      path: '/about',
      element: <><Navbar /><About /></>
    },
    {
      path: '/contact',
      element: <><Navbar /><Contact /></>
    }

  ]);
  return (
    <>
    <RouterProvider router={router} />
    </>
  );
}

export default App;
