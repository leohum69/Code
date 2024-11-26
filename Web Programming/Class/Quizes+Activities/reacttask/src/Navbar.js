import React from 'react';
import { NavLink } from 'react-router-dom';

const Navbar = () => {
    return(
        <div>
            <nav>
                <NavLink className={(e)=>{return e.isActive?"g":""}} to='/'><li>Home</li></NavLink>
                <NavLink className={(e)=>{return e.isActive?"g":""}} to='/About'><li>About</li></NavLink>
                <NavLink className={(e)=>{return e.isActive?"g":""}} to='/contact'><li>Contact Us</li></NavLink>
            </nav>
        </div>
    );
};

export default Navbar;