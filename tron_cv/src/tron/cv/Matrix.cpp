/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/cv/Matrix.h"

namespace tron
{
void Matrix::getCorrespondences(cv::Mat mat, float threshold, std::vector<cv::Vec2i>& listCorrespondences)
{    
    double maxVal; 
    cv::Point maxLoc;
    int row, col;
    bool bsearch = true;
    
    // clone input matrix, to avoid altering it
    cv::Mat mat2 = mat.clone();
    
    // clear correspondences
    listCorrespondences.clear();
    
    // searching until no more correspondences found
    while (bsearch)
    {
        // find maximum value
        cv::minMaxLoc(mat2, NULL, &maxVal, NULL, &maxLoc);
        
        // if value found above the threshold
        if (maxVal > threshold)
        {
            row = maxLoc.y;   
            col = maxLoc.x;    
            
            // add correspondence
            listCorrespondences.push_back(cv::Vec2i(row, col));

            // and clear other matrix relations of both elements
            mat2.row(row).setTo(0);                
            mat2.col(col).setTo(0);                
        }                
        // otherwise, finish search
        else
            bsearch = false;
    }    
}
}
							 