'''
Created By    : Code and Robot ID
Project       : Turn ON/Off Lamp Using Hand Tracking
Version       : 02
Date (update) : 28 Mei 2024
'''

from cvzone.HandTrackingModule import HandDetector
import cv2
from cvzone.FPS import FPS

# Initialize the FPS class with an average count of 30 frames for smoothing
fpsReader = FPS(avgCount=30)

# Initialize the webcam to capture video
cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("Error: Could not open video stream.")
    exit()

cap.set(cv2.CAP_PROP_FPS, 30)  # Set the frames per second to 30

# Initialize the HandDetector class with the given parameters
detector = HandDetector(staticMode=False, maxHands=2, modelComplexity=1, detectionCon=0.5, minTrackCon=0.5)

print("Starting video capture...")
# Continuously get frames from the webcam
while True:
    # Capture each frame from the webcam
    success, img = cap.read()
    if not success:
        print("Error: Could not read frame.")
        break

    # Update the FPS counter and draw the FPS on the image
    fps, img = fpsReader.update(img, pos=(20, 50),
                                bgColor=(255, 0, 255), textColor=(255, 255, 255),
                                scale=3, thickness=3)

    # Find hands in the current frame
    hands, img = detector.findHands(img, draw=True, flipType=True)

    # Check if any hands are detected
    if hands:
        # Information for the first hand detected
        hand1 = hands[0]  # Get the first hand detected
        lmList1 = hand1["lmList"]  # List of 21 landmarks for the first hand
        bbox1 = hand1["bbox"]  # Bounding box around the first hand (x,y,w,h coordinates)
        center1 = hand1['center']  # Center coordinates of the first hand
        handType1 = hand1["type"]  # Type of the first hand ("Left" or "Right")

        # Count the number of fingers up for the first hand
        fingers1 = detector.fingersUp(hand1)
        print(f'H1 ({handType1})= {fingers1.count(1)}', end=" ")  # Print the count of fingers that are up

        # Calculate distance between specific landmarks on the first hand and draw it on the image
        length, info, img = detector.findDistance(lmList1[8][0:2], lmList1[12][0:2], img, color=(255, 0, 255), scale=10)

        # Check if a second hand is detected
        if len(hands) == 2:
            hand2 = hands[1]
            lmList2 = hand2["lmList"]
            bbox2 = hand2["bbox"]
            center2 = hand2['center']
            handType2 = hand2["type"]

            # Count the number of fingers up for the second hand
            fingers2 = detector.fingersUp(hand2)
            print(f'H2 ({handType2})= {fingers2.count(1)}', end=" ")

            # Calculate distance between the index fingers of both hands and draw it on the image
            length, info, img = detector.findDistance(lmList1[8][0:2], lmList2[8][0:2], img, color=(255, 0, 0), scale=10)

        print(" ")

    # Display the image in a window
    cv2.imshow("Image", img)

    # Keep the window open and update it for each frame; wait for 1 millisecond between frames
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the webcam and destroy all windows
cap.release()
cv2.destroyAllWindows()
