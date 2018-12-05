
//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������01
//		����������OpenCV�������������ã�����һ��ͼƬ����ʾ
//		�����������ò���ϵͳ�� Windows 7 64bit
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��11�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------

#include <opencv2/highgui/highgui.hpp> //ͷ�ļ�
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
using namespace cv; //����cv�����ռ�

int main()
{
	Mat edge,grayImages;
	// ��1������һ��ͼƬ
	Mat srcImage=imread("1.jpg");
	imshow ("picture1",srcImage);
	Mat element=getStructuringElement(MORPH_RECT,Size(15,15));
	Mat dstImage;
	erode(srcImage,dstImage,element);
	// ��2���ڴ�������ʾ�����ͼƬ
	imshow("picture2",dstImage);
	cvtColor(srcImage,grayImages,CV_BGR2GRAY);
	blur(grayImages,edge,Size(3,3));
	Canny(edge,edge,3,9,3);
	imshow("picture3",edge);
	// ��3���ȴ�6000 ms�󴰿��Զ��ر�
	waitKey(6000);
}
