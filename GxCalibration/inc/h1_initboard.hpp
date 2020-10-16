#ifndef _H1_INITBOARD_HPP_
#define _H1_INITBOARD_HPP_

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


Mat createBoard(int width = 10, int height = 8, int side_length = 100, String filePath = "chessboard.png")
{
    Mat board(height * side_length, width * side_length, CV_8UC3);
    for (int i = 0; i < height * side_length; i++)
    {
        for (int j = 0; j < width * side_length; j++)
        {
            if ((j / side_length % 2 == 1 && i / side_length % 2 == 0) || (j / side_length % 2 == 0 && i / side_length % 2 == 1))
            {
                board.at<Vec3b>(i, j)[0] = 255;
                board.at<Vec3b>(i, j)[1] = 255;
                board.at<Vec3b>(i, j)[2] = 255;
            }
        }
    }

    imwrite(filePath, board);
    imshow(filePath, board);
    waitKey(0);
    return board;
}

int init_board(int argc, char **argv)
{
    String keys =
        "{     help|               | print this message   }"
        "{        w|             10|  width: the Number of squares at the bottom of the chessboard }"
        "{        h|              8| height: the Number of squares at the side of the chessboard }"
        "{        l|            100| length: the pixel length of square in the chessboard }"
        "{     path| ../img/chessboard.jpg| length: the pixel length of square in the chessboard }";

    CommandLineParser parser(argc, argv, keys);
    int width = parser.get<int>("w");
    int height = parser.get<int>("h");
    int length = parser.get<int>("l");
    String path = parser.get<String>("path");
    createBoard(width, height, length, path);

    char temp[48];
    sprintf(temp, "a %d*%d chessboard has been created", width, height);

    cout << temp << endl;
    return 0;
}



#endif