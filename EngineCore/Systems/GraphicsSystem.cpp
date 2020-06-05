//
// Created by kiku on 26.05.2020.
//

#include "GraphicsSystem.h"

GraphicsSystem::GraphicsSystem(int _width, int _height) : ScreenHeight(_height), ScreenWidth(_width)
{
    m_Viewer = new GraphicsEngine::Viewer(ScreenWidth, ScreenHeight);
    m_State = true;
}

GraphicsSystem::~GraphicsSystem()
{
    delete m_Viewer;
}

std::string GraphicsSystem::GetName() const
{
    return "GraphicsSystem";
}

void GraphicsSystem::Update()
{
    if(m_Viewer->IsWindowClose())
    {
        m_State = false;
        return;
    }
    m_Viewer->Clear();

    for(auto updVO : m_RegisteredEntitys)
    {
        auto position = updVO.second->gn->GetPosition();
        updVO.second->vo->setPosition(glm::vec3(position.GetX(), position.GetY(), 0));

        auto rotation = updVO.second->gn->GetPosition().GetAngle();
        updVO.second->vo->setRotation(rotation, glm::vec3(0.f,0.f,1.f));
    }

    m_Viewer->Draw();
}

void GraphicsSystem::Register(Entity& entity)
{
    if (m_RegisteredEntitys.find(&entity) != m_RegisteredEntitys.end())
    {
        throw std::invalid_argument("Entity already registered!");
    }

    auto node = new GraphicsNode(
            *((PositionComponent*)entity.Get("PositionComponent")),
            *((ShapeComponent*)entity.Get("ShapeComponent")));

    GraphicsEngine::ViewObject* vo = nullptr;

    auto name = node->GetShape().GetShape().GetName();
    if (name == "Circle")
    {
        auto circle = ((const Circle&)node->GetShape().GetShape());
        vo = new GraphicsEngine::Circle(
                circle.GetCenter().x, circle.GetCenter().y, 0, circle.GetR());
        m_Viewer->AddObjectToPool(vo);
    }
    else if(name == "Polygon")
    {
        auto pol = (const Polygon&)node->GetShape().GetShape();
        auto size = pol.GetLength();
        switch(size)
        {
            case 4: {
                auto pos = new float[4 * 3]{0.f};
                for(int i = 0; i < size; i ++)
                {
                    pos[(i * 3)] = pol[i].x;
                    pos[(i * 3) + 1] = pol[i].y;
                    pos[(i * 3) + 2] = 0;
                }
                vo = new GraphicsEngine::Rectangle(node->GetPosition().GetX(), node->GetPosition().GetY(), pos);
                m_Viewer->AddObjectToPool(vo);
                break;
            }
            case 3: {
                auto pos = new float[3 * 3]{0.f};
                for(int i = 0; i < size; i ++)
                {
                    pos[(i * 3)] = pol[i].x;
                    pos[(i * 3) + 1] = pol[i].y;
                    pos[(i * 3) + 2] = 0;
                }
                vo = new GraphicsEngine::Triangle(node->GetPosition().GetX(), node->GetPosition().GetY(), pos);
                m_Viewer->AddObjectToPool(vo);
                break;
            }
            default:
                break;
        }
    }

    m_RegisteredEntitys[&entity] = new GNodeVOPair(node, vo);
}

void GraphicsSystem::Unregister(Entity& entity)
{
    if(m_RegisteredEntitys.find(&entity) == m_RegisteredEntitys.end())
    {
        std::cout << "There is no Entity like that in [RegisteredEntitys]\n";
        return;
    }

    delete m_RegisteredEntitys[&entity]->vo;
    delete m_RegisteredEntitys[&entity]->gn;
    m_RegisteredEntitys.erase(&entity);
}

bool GraphicsSystem::GetWinState() {
    return m_State;
}

GraphicsSystem::GNodeVOPair::GNodeVOPair(GraphicsNode* gn, GraphicsEngine::ViewObject* vo)
{
    this->gn = gn;
    this->vo = vo;
}
