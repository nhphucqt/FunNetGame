#ifndef MAIN_MENU_ACTIVITY_HPP
#define MAIN_MENU_ACTIVITY_HPP

#include <Activity.hpp>

class MainMenuActivity : public Activity {
protected:
    virtual void onEvent(const sf::Event& event) override;
    virtual void onCreate() override;
    virtual void onLoadResources() override;
    virtual void onAttach() override;
    virtual void onResume() override;
    virtual void onPause() override;
    virtual void onDestroy() override;
    void updateCurrent(sf::Time dt) override;
    virtual void onActivityResult(int requestCode, ResultCode resultCode, Intent::Ptr data) override;

private:

};

#endif