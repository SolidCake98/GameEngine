//
// Created by kiku on 26.05.2020.
//

#ifndef GAMEENGINE_GRAPHICSSYSTEM_H
#define GAMEENGINE_GRAPHICSSYSTEM_H

#include <stdexcept>

#include "../../GraphicsEngine/Viewer.h"
#include "SystemBase.h"
#include "../Nodes/GraphicsNode.h"
#include "../Shapes/Polygon.h"
#include "../Shapes/Circle.h"

class GraphicsSystem : public SystemBase {
public:
    const int ScreenWidth;
    const int ScreenHeight;

    GraphicsSystem(int, int);
    ~GraphicsSystem();

    std::string GetName() const override;
    void Update() override;
    void Register(Entity&) override;
    void Unregister(Entity&) override;

    bool GetWinState();

private:
    struct GNodeVOPair
    {
        GraphicsNode* gn;
        GraphicsEngine::ViewObject* vo;

        GNodeVOPair(GraphicsNode*, GraphicsEngine::ViewObject*);
    };

    bool m_State;

    std::map<Entity*, GNodeVOPair*> m_RegisteredEntitys;
    GraphicsEngine::Viewer* m_Viewer;
};


#endif //GAMEENGINE_GRAPHICSSYSTEM_H
