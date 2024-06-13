#include <iostream>
using namespace std;

/**
 * @note Built-in physics engine for Engine3D API design
 * @note These are notes that will be used when there comes a discussion to work on this physics engine.
 * @note Including bits of pieces to discuss.
 * @note These is some example code on how I am considering in developing the physics engine
 * @note Open for discussion in terms of looking in how we may want users to call our API
 *      @note #1 An effective api that allows to easily create our physics world.
 *      @note #2 Easy to use to create a world that can be easily applied to users own renderer.
 *      @note #3 Having option to Enable/disable synchronization. (TBD)
 *      @note #4 Consider various design flaws including api function calls, vtables, seeing if some of the things should be decided either during runtime/compile-time.
*/
namespace engine3d{
    namespace physics{
        //! @note ActorObject that is just an example that pretends to be a type of physics object with Collision and Tick capabilities
        class ActorObject{
        public:
            virtual ~ActorObject() = default;

        private:
            virtual void OnTick(){}
            virtual void OnCollision(){}
        };
    };
};

//! @note Treating if we were to have a 3D cube to render
//! @note Cube as an actor that will have physics properties
//! @note Seeing various API's that could work to easily create a physics object and automatically rendering that to the screen
//! @note Rendering portion should be subjective and agnostic enough to be used inside your renderer.
class CubeActor : public engine3d::physics::ActorObject{
public:
    ~CubeActor() = default;

    void InitiateActor(){

    }

    bool IsCollided(){
        OnCollision();
        return m_IsCollided;
    }

private:
    void OnTick() override{}

    void OnCollision() override {
        if(!m_IsCollided) m_IsCollided = true;
    }

    bool m_IsCollided = false;
};

int main(){
    CubeActor cube;
    cube.InitiateActor();

    if(cube.IsCollided()){
        cout << "[CUBE TEST] -- Collision was true!\n";
    }
    return 0;
}