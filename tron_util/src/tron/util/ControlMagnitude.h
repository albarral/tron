#ifndef __TRON_UTIL_CONTROL_MAGNITUDE_H
#define __TRON_UTIL_CONTROL_MAGNITUDE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/
 
namespace tron
{
// Class used to easily control a given magnitude based in a low-normal-high mode.
// 3 types of magnitude changes are allowed: model, additive and proportional.
// Additive and proportional changes are done by prefixed quantities (mode is set to manual on these changes).
class ControlMagnitude
{    
 public:
    /*! magnitude modes */
    enum eModes
    {
         eMAG_LOW,
         eMAG_NORMAL,                       
         eMAG_HIGH,                       
         eMAG_MANUAL
    };

private:
    int mode;              // selected mode (low, normal, high or manual)
    float value;            // magnitude value
    // params (prefixed)
    float low;              // low value for magnitude
    float normal;         // normal value for magnitude
    float high;            // high value for magnitude
    float change;       // amount of additive changes 
    float xchange;       // amount of proportional changes 
    
public:  
    ControlMagnitude();
    
     // set low value
    void setLow(float value);
    // set normal value
    void setNormal(float value);
    // set high value
    void setHigh(float value);
   // sets the low, normal and high values
    void setValues(float low, float normal, float high);        
    // sets the additive and proportional changes
    void setChanges(float additiveChange, float proportionalChange);

    int getMode() {return mode;};    
    float getValue() {return value;};
    float getLow() {return low;};
    float getNormal() {return normal;};
    float getHigh() {return high;};
    
    // change magnitude to low value
    void set2Low();
    // change magnitude to normal value
    void set2Normal();
    // change magnitude to high value
    void set2High();

    // additive increase of the value (a prefixed amount)
    void increase();
    // additive decrease of the value (a prefixed amount)
    void decrease();
    // proportional increase of the value (a prefixed amount)
    void increaseX();
    // proportional decrease of the value (a prefixed amount)
    void decreaseX();
    
private: 
    // set specified mode (changing magnitude to proper value)
    void setMode(int mode);
};
}
#endif
