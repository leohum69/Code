import React, { useState } from 'react';
import Header from './Header';


<Header />
function Chat() {
  const [isTeacherResponding, setIsTeacherResponding] = useState(false);
  const [messages, setMessages] = useState([]);

  const sendMessage = () => {
    const messageInput = document.getElementById('messageInput');
    const message = messageInput.value.trim();
  
    if (message !== '') {
      const className = isTeacherResponding ? 'teacher' : 'student';
      const newMessage = { className, text: message };
  
      // Update state with the new message
      setMessages((prevMessages) => [...prevMessages, newMessage]);
      messageInput.value = '';
  
      // Simulate teacher's response
      if (!isTeacherResponding) {
        const response = 'Thank you for your question! Here is the answer.';
        const replyMessage = { className: 'teacher', text: response };
  
        setTimeout(() => {
          // Append the teacher's response
          setMessages((prevMessages) => [...prevMessages, replyMessage]);
          setIsTeacherResponding(false); // Reset responding state
        }, 1000);
      } else {
        setIsTeacherResponding(false); // Ensure the state toggles properly
      }
    }
  };
  
  

  return (
    <div>
      <header>
        <h1>PeerLearn HUB - Chat</h1>
      </header>
      <main>
        <div className="chat-container" id="chatContainer">
          <div className="chat-box" id="chatBox">
            {messages.map((message, index) => (
              <div key={index} className={`message ${message.className}`}>
                <p>{message.text}</p>
              </div>
            ))}
          </div>
        </div>
        <div className="chat-input">
          <input type="text" id="messageInput" placeholder="Type your message..." />
          <button onClick={sendMessage}>Send</button>
        </div>
      </main>
    </div>
  );
}

export default Chat;
