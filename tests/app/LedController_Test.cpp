#include <gtest/gtest.h>

#include "../../app/inc/LedController.h"
#include "../../mocks/inc/LedMockDevice.h"

struct LedControllerFixture : public testing::Test {
    void SetUp() {
        ledcontroller_create();
        pLedDriver mockdev = ledmockdevice_create(0);
        ledcontroller_add(0, mockdev);
    }

    void TearDown() {
        ledcontroller_destroy();
    }
};

TEST_F(LedControllerFixture, TurnOnLed) {
    ledcontroller_turnon(0);
    int result = ledcontroller_getstatus(0);
    ASSERT_EQ(result, 1);
}

TEST(Test_1, CASE_1) {
    ASSERT_EQ(1, 1);
}
