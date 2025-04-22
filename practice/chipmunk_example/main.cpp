#include <chipmunk/chipmunk.h>
#include <iostream>

int main() {
    // Initialize Chipmunk
    //cpInitChipmunk();

    // Create space with gravity
    cpSpace* space = cpSpaceNew();
    cpVect gravity = cpv(0, -100); // downward gravity
    cpSpaceSetGravity(space, gravity);

    // Create ground (static body)
    cpBody* staticBody = cpSpaceGetStaticBody(space);
    cpShape* ground = cpSegmentShapeNew(staticBody, cpv(-200, 0), cpv(200, 0), 0);
    cpShapeSetFriction(ground, 1.0);
    cpSpaceAddShape(space, ground);

    // Create dynamic body (chipmunk ball)
    cpFloat mass = 1.0;
    cpFloat radius = 10.0;
    cpFloat moment = cpMomentForCircle(mass, 0, radius, cpvzero);
    cpBody* body = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    cpBodySetPosition(body, cpv(0, 100));
    cpShape* shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius, cpvzero));
    cpShapeSetFriction(shape, 0.7);

    // Step through simulation
    const cpFloat dt = 1.0 / 60.0;
    for (int i = 0; i < 180; ++i) {
        cpSpaceStep(space, dt);
        cpVect pos = cpBodyGetPosition(body);
        std::cout << "Step " << i << ": Ball at (" << pos.x << ", " << pos.y << ")\n";
    }

    // Cleanup
    cpShapeFree(shape);
    cpBodyFree(body);
    cpShapeFree(ground);
    cpSpaceFree(space);

    return 0;
}
