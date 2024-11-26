# Cyber Triage Tool

## Overview
The Cyber Triage Tool is a web-based application designed for video analysis. It allows users to upload video files, extract frames at specified intervals, and interact with the extracted frames through a user-friendly interface.

## Features
- **Video Upload**: Users can upload video files for analysis.
- **Frame Extraction**: Extract frames from the video at automatic or custom intervals.
- **Frame Interaction**: View and interact with extracted frames.
- **Responsive Design**: The interface is designed to be responsive and user-friendly across different devices.

## Technologies Used
- **Frontend**: HTML, CSS, JavaScript, jQuery
- **Backend**: Flask (Python)
- **Video Processing**: OpenCV (Python)

## Installation
1. Unzip the Zip:
    ```bash
    cd i221749_i220518_i221697_i221636
    ```
2. Install the required Python packages:
    ```bash
    pip install -r requirements.txt
    ```
3. Run the Flask application:
    ```bash
    python app.py
    ```
4. Open your web browser and navigate to `http://127.0.0.1:5000`.

## Usage
1. **Upload Video**: Click on the "Choose File" button to select a video file from your computer.
2. **Load Video**: Click on the "Load Video" button to upload and process the video.
3. **Select Interval**: Choose between automatic interval or custom interval for frame extraction.
4. **View Frames**: Extracted frames will be displayed below the video player. Click on any frame to seek to that position in the video.

## File Structure
- **static/**: Contains static files such as uploaded videos and extracted frames.
- **templates/**: Contains HTML templates for the web application.
- **app.py**: Main Flask application file.
- **requirements.txt**: List of required Python packages.

## Acknowledgements
- [Flask](https://flask.palletsprojects.com/)
- [OpenCV](https://opencv.org/)
- [jQuery](https://jquery.com/)

