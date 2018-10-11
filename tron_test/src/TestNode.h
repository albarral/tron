#ifndef ___TRON_TEST_TESTNODE_H
#define ___TRON_TEST_TESTNODE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/Node.h"

// Definition of arm node sections and channels
 class TestNode : public tron::Node
{
public:
    /*! arm sections */
    enum eArmSections
    {
        eSECTION_JOINTS,             /*! joints section */
        eSECTION_AXES,                /*! axes section  */
        eSECTION_DIM
    };     

    /*! joints section channels */
    enum eJointsChannels
    {
         eJOINTS_HS,                         /*! horizontal shoulder position (degrees)*/
         eJOINTS_VS,                         /*! vertical shoulder position (degrees) */
         eJOINTS_ELB,                        /*! elbow position (degrees) */
         eJOINTS_DIM
    };

    /*! axes section channels  */
    enum eAxesChannels
    {
         eAXES_PAN,                       /*! pan position (degrees) */
         eAXES_TILT,                       /*! tilt position (degrees) */
         eAXES_RAD,                       /*! radial position (cm) */
         eAXES_DIM
    };
    
    
 private:
    /*! names of arm sections */
    const std::string SECTION_JOINTS = "joints";
    const std::string SECTION_AXES = "axes";
    
    /*! names of joints section channel */
    const std::string JOINTS_HS = "hs";          /*! horizontal shoulder position */
    const std::string JOINTS_VS = "vs";          /*! vertical shoulder position  */
    const std::string JOINTS_ELB = "elb";        /*! elbow position  */
    
    /*! names of axes section channels */
    const std::string AXES_PAN = "pan";                 /*! pan position (degrees) */
    const std::string AXES_TILT = "tilt";                   /*! tilt position (degrees) */
    const std::string AXES_RAD = "rad";                  /*! radial position (cm) */
    
     
    void setJointsSection();
    void setAxesSection();
    
 public:     
   TestNode();
    
    // return node description
    virtual std::string toString() override;             
};
#endif
