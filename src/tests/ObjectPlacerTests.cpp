#include "ObjectPlacer/ObjectPlacer.h"
#include "ObjectPlacer/LandScape.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class LandScapeStub : public IObjectFactory {
public:
    virtual std::vector<IObject> make() override { return std::vector<IObject>(10); };
};

class LandScapeMock : public IObjectFactory {
public:
    MOCK_METHOD(std::vector<IObject>, make, (), (override));
};

class ObjectPlacerTestFixture : public testing::Test {
public:

    std::unique_ptr<ObjectPlacer> objectPlacer_;

    std::unique_ptr<LandScapeStub> landScapeStub_;

    std::unique_ptr<LandScapeMock> landScapeMock_;

    void SetUp() {
        landScapeStub_ = std::make_unique<LandScapeStub>();
        landScapeMock_ = std::make_unique<LandScapeMock>();
    };

};

TEST_F(ObjectPlacerTestFixture, ObjectPlacerLandScapeMakeCall) {

    auto &landScapeMock = *(landScapeMock_.get());
    objectPlacer_ = std::make_unique<ObjectPlacer>(std::move(landScapeMock_));
    EXPECT_CALL(landScapeMock, make);

    objectPlacer_->makeLandScape();
}

TEST_F(ObjectPlacerTestFixture, LandScapeObjectsReturn) {
    const int stubObjectNUm = 10;
    objectPlacer_ = std::make_unique<ObjectPlacer>(std::move(landScapeStub_));
    EXPECT_EQ(objectPlacer_->makeLandScape().size(), stubObjectNUm);
}

TEST(LandScapeTestSuit, LandScapeMakeCall) {
    LandScape landScape;
    EXPECT_GT(landScape.make().size(), 1);
}