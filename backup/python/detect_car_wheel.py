
import cv2
import numpy as np
import matplotlib.pyplot as plt

#function to convert an image to sketch
def canny(image):
    #to change the image to gray scale
    gray=cv2.cvtColor(image,cv2.COLOR_RGB2GRAY)
    #to reduce noice in grayscale image
    blur=cv2.GaussianBlur(gray,(5,5),0)
    #used to meashure the change in intensity and produce a outline of gray image
    #syntax: cv2.Canny(image,low_threshold,high_threshold)
    image=cv2.Canny(blur,50,150)
    return image

# Read image.
image=cv2.imread('car1.jpg', cv2.IMREAD_COLOR)
img = np.copy(image)
img=cv2.resize(img,(640,331),interpolation = cv2.INTER_AREA)
canny_image=canny(img)
dictimg={1:img,2:canny_image}

# Convert to grayscale.
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Blur using 3 * 3 kernel.
gray_blurred = cv2.blur(gray, (3, 3))

# Apply Hough transform on the blurred image.
detected_circles = cv2.HoughCircles(gray_blurred,
                   cv2.HOUGH_GRADIENT, 1, 20, param1 = 50,
               param2 = 30, minRadius = 25, maxRadius = 40)

# Draw circles that are detected.
if detected_circles is not None:

    # Convert the circle parameters a, b and r to integers.
    detected_circles = np.uint16(np.around(detected_circles))
    itr=1
    crop=[None]*2
    for pt in detected_circles[0, :]:
        a, b, r = pt[0], pt[1], pt[2]

        # Draw the circumference of the circle.
        # cv2.circle(image, center_coordinates, radius, color, thickness)
        ndimage=cv2.circle(img, (a, b), (r), (0, 255, 0), 2)
        #rectangle
        # cv2.rectangle(image, start_point, end_point, color, thickness)
        rect_start_x=a-(r+30)
        rect_start_y=b-(r+30)
        rect_end_x=a+(r+30)
        rect_end_y=b+(r+20)
        #ndimage=cv2.rectangle(img, (rect_start_x,rect_start_y), (rect_end_x,rect_end_y), (0,255,0), 2)
        # cropped_image
        # We first supply the startY and endY coordinates, followed by the startX and endX coordinates to the slice
        dictimg[itr] = img[rect_start_y:rect_end_y,rect_start_x:rect_end_x]
        itr=itr+1

        # Draw a small circle (of radius 1) to show the center.
        cv2.circle(img, (a, b), 1, (0, 0, 255), 3)
    imgwidth=ndimage.shape[1]/2
    imgheight=ndimage.shape[0]
    dim=(imgwidth,imgheight)
    #shrink the images
    #resized = cv2.resize(img, dim, interpolation = cv2.INTER_AREA)
    ndimage=cv2.resize(ndimage,dim,interpolation = cv2.INTER_AREA)
    cv2.imshow("Detected Circle", img)
    cv2.waitKey(0)


    #My_img = cv2.addWeighted(img, 0.3, ndimage, 0.7, 0)
    cv2.imshow("Detected Circle", ndimage)
    cv2.waitKey(0)
    '''
    cv2.imshow("Detected Circle", dictimg[1])
    cv2.waitKey(0)
    cv2.imshow("Detected Circle", dictimg[2])
    cv2.waitKey(0)'''
