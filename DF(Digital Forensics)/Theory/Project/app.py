from flask import Flask, render_template, request, jsonify, send_from_directory
import os
import threading
import time
import cv2

app = Flask(__name__)

# Folder to store uploaded videos
UPLOAD_FOLDER = 'static/uploaded_videos'
EXTRACTED_FRAMES_FOLDER = 'static/extracted_frames'
os.makedirs(UPLOAD_FOLDER, exist_ok=True)
os.makedirs(EXTRACTED_FRAMES_FOLDER, exist_ok=True)

video_capture = None
frame_interval = 1000  # Default interval in ms for automatic mode
current_frame = 0
fps = 0
is_paused = threading.Event()
is_paused.set()  # Initially paused

output_folder = None
video_path = None
extraction_thread = None
extraction_thread_running = False  # To check if the thread is running

def extract_frames():
    global video_capture, current_frame, is_paused, output_folder, extraction_thread_running, frame_interval,fps

    print(f"Extraction thread started with interval: {frame_interval} ms")  # Debug line
    extraction_thread_running = True

    # Get the video's frames per second (FPS) to calculate frames between intervals
    fps = video_capture.get(cv2.CAP_PROP_FPS)
    if fps <= 0:  # Set a default FPS if the video doesn't provide a valid one
        fps = 30  # Assuming 30 FPS as a default
    frame_step = int((frame_interval / 1000) * fps)  # Frames to skip between extractions

    print(f"Frame step: {frame_step} fps {fps}")  # Debug line

    while True:
        if video_capture:
            # Move to the next frame according to frame_step
            video_capture.set(cv2.CAP_PROP_POS_FRAMES, current_frame)

            ret, frame = video_capture.read()
            if not ret:
                break  # Exit if no more frames are available

            # Save the current frame
            print(f"Saving frame {current_frame}")  # Debug line
            save_frame(frame, current_frame)

            # Move to the next frame based on the calculated frame step
            current_frame += frame_step
            #time.sleep(frame_interval / 1000)  # Wait according to the interval in seconds

        else:
            time.sleep(0.1)  # Wait while paused

    extraction_thread_running = False
    print("Extraction thread finished")  # Debug line


def save_frame(frame, frame_count):
    global output_folder
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    frame_filename = os.path.join(output_folder, f"frame_{frame_count}.jpg")
    cv2.imwrite(frame_filename, frame)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/load_video', methods=['POST'])
@app.route('/load_video', methods=['POST'])
def load_video():
    global video_capture, output_folder, video_path, current_frame, extraction_thread, extraction_thread_running, frame_interval
    
    video_file = request.files['video_file']
    interval_option = request.form.get('intervalOption')  # This will be either 'automatic' or 'custom'
    custom_interval = request.form.get('custom_interval', type=int, default=1000)  # Default to 1000 ms if not provided
    print(f"Selected interval option: {interval_option}, custom interval: {custom_interval}")  # Debug line
    # Adjust the frame interval based on the selected option
    if interval_option == 'custom' and custom_interval >= 100:
        frame_interval = custom_interval  # Use the custom interval if it's 100 ms or more
    else:
        frame_interval = 2000  # Default to 2000 ms for automatic mode, or invalid custom interval

    # Save the uploaded video to the static folder
    video_path = os.path.join(UPLOAD_FOLDER, video_file.filename)
    video_file.save(video_path)

    # Close the previous video capture if it exists
    if video_capture is not None:
        video_capture.release()

    video_capture = cv2.VideoCapture(video_path)
    video_name = os.path.splitext(os.path.basename(video_path))[0]
    timestamp = time.strftime("%Y%m%d-%H%M%S")
    output_folder = os.path.join(EXTRACTED_FRAMES_FOLDER, f"{video_name}_{timestamp}")
    current_frame = 0

    # Start the extraction thread if it's not already running
    if not extraction_thread_running:
        extraction_thread = threading.Thread(target=extract_frames, daemon=True)
        extraction_thread.start()

    # Return response with status and video URL
    return jsonify({
        'status': 'Video loaded successfully', 
        'video_url': f'/static/uploaded_videos/{video_file.filename}',
        'interval': frame_interval  # Optionally send the selected interval back to the client
    })

@app.route('/get_extracted_frames')
def get_extracted_frames():
    global output_folder
    if not output_folder or not os.path.exists(output_folder):
        return jsonify([])

    frame_files = sorted(os.listdir(output_folder))
    frames_data = [{'url': f'/static/extracted_frames/{os.path.basename(output_folder)}/{file}', 
                    'frame': int(file.split('_')[1].split('.')[0]),'lol' : fps} 
                   for file in frame_files]
    print("Frames data:", frames_data)  # Debugging line to check paths
    return jsonify(frames_data)

if __name__ == '__main__':
    app.run(debug=True)
