
//--------------------------------------【程序说明】-------------------------------------------
//		程序说明：《OpenCV3编程入门》OpenCV3版书本配套示例程序01
//		程序描述：OpenCV开发环境的配置，载入一张图片并显示
//		开发测试所用操作系统： Windows 7 64bit
//		开发测试所用IDE版本：Visual Studio 2010
//		开发测试所用OpenCV版本：	3.0 beta
//		2014年11月 Created by @浅墨_毛星云
//		2014年11月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------

#include <opencv2/highgui/highgui.hpp> //头文件
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
using namespace cv; //包含cv命名空间

int main()
{
	Mat edge,grayImages;
	// 【1】读入一张图片
	Mat srcImage=imread("1.jpg");
	imshow ("picture1",srcImage);
	Mat element=getStructuringElement(MORPH_RECT,Size(15,15));
	Mat dstImage;
	erode(srcImage,dstImage,element);
	// 【2】在窗口中显示载入的图片
	imshow("picture2",dstImage);
	cvtColor(srcImage,grayImages,CV_BGR2GRAY);
	blur(grayImages,edge,Size(3,3));
	Canny(edge,edge,3,9,3);
	imshow("picture3",edge);
	// 【3】等待6000 ms后窗口自动关闭
	waitKey(6000);
}
