from ultralytics import YOLO
import cv2

def test():

    # Load a pretrained YOLO model
    model = YOLO('runs/detect/train4/weights/best.pt')

    # Inference Source - a single source
    src = cv2.imread("datasets/dataset_mask/images/testing/mask-teens.jpg")

    # Perform object detection on an image using the model
    result = model.predict(source=src, save=True, save_txt=True)  # save predictions as labels

    # View result
    for r in result:
        # print the Boxes object containing the detection bounding boxes
        print(r.boxes)

        # Plot results image
        print("result.plot()")
        dst = r.plot()  # return BGR-order numpy array
        cv2.imshow("result plot", dst)

        # Plot the original image (NParray)
        print("result.orig_img")
        cv2.imshow("result orig", r.orig_img)

    # Save results to disk
    r.save(filename='result.jpg')
    cv2.waitKey(0)
    
if __name__ == '__main__':
    test()

