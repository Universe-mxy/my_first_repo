int main（）
{
// 读取图片
cv::Mat bgr img;
bgr img = cv::imread("587.jpg");
// 彩色图转灰度图
cv::Mat gray img;
cv::cvtColor(bgr img,gray img,cv::COLOR BGR2GRAY);
//显示灰度图,调试用
cv::resize(gray img,gray img,{}，0.5，0.5);
cv::imshow("gray",gray img);
cv::resize(gray_img, gray_img,{},2,2);
//进行二值化
cv::Mat binary img;
cv::threshold(gray img,binary img, 120,255, CV::THRESH BINARY);
// 显示二值图,调试用
cv::resize(binary img,binary img,{},0.5,0.5)
cv::imshow("binary img",binary img);
cv::resize(binary img,binary img,{},2,2);
// 获取轮廓点
std::vector<std::vector<cv::Point>> contours:cv::findcontours(binary img, contourS, CV::RETR EXTERNAL, CV::CHAIN APPROX NONE);
//显示轮廓点，调试用
cv::Mat drawcontours=bgr img.clone();
for(const auto & contour :contours){
    tools::draw points(drawcontours,contour);
}
cv::resize(drawcontours,drawcontours,{}，0.5,0.5);
cv::imshow("drawcontours",drawcontours);

//获取旋转矩形并显示，示范用
std::vector<cv::RotatedRect>rotated rects;
for(const auto & contour : contours){
    auto rotated rect=cv::minAreaRect(contour);
    rotated rects.emplace back(rotated rect);
}
cv::Mat drawrect = bgr img.clone();
for(const auto & rotated rect :rotated rects){
    std::vector<cv::Point2f> points(4);
    rotated rect.points(&points[0]);
    tools::draw points(drawrect, points);
    }
cv::resize(drawrect,drawrect,{}，0.5，0.5);
cv::imshow("drawrect",drawrect);

cv::waitkey(0);
return 0;
}