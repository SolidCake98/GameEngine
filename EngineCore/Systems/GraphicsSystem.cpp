//
// Created by kiku on 26.05.2020.
//


#include "GraphicsSystem.h"

GraphicsSystem::GraphicsSystem()
{
    m_Viewer = new GraphicsEngine::Viewer(640, 480);
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
    m_Viewer->clear();

    for(auto updVO : m_registeredEntitys)
    {
        auto position = updVO.second->gn->GetPosition();
        updVO.second->vo->setPosition(glm::vec3(position.GetX(), position.GetY(), 0));

        auto rotation = updVO.second->gn->GetPosition().GetAngle();
        updVO.second->vo->setRotation(rotation, glm::vec3(0.f,0.f,1.f));
    }

    m_Viewer->draw();
}

void GraphicsSystem::Register(Entity& entity)
{
    if (m_registeredEntitys.find(&entity) != m_registeredEntitys.end())
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
        m_Viewer->addObjectToPool(*vo);
    }
    else if(name == "Polygon")
    {
        auto pol = (const Polygon&)node->GetShape().GetShape();
        auto size = pol.GetLength();
        switch(size)
        {
            case 4: {
                float pos[4 * 3]{0.f};
                for(int i = 0; i < size; i ++)
                {
                    pos[(i * 3)] = pol[i].x;
                    pos[(i * 3) + 1] = pol[i].y;
                    pos[(i * 3) + 2] = 0;
                }
                vo = new GraphicsEngine::Rectangle(node->GetPosition().GetX(), node->GetPosition().GetY(), pos);
                m_Viewer->addObjectToPool(*vo);
                break;
            }
            case 3: {
                float pos[3 * 3]{0.f};
                for(int i = 0; i < size; i ++)
                {
                    pos[(i * 3)] = pol[i].x;
                    pos[(i * 3) + 1] = pol[i].y;
                    pos[(i * 3) + 2] = 0;
                }
                vo = new GraphicsEngine::Triangle(node->GetPosition().GetX(), node->GetPosition().GetY(), pos);
                m_Viewer->addObjectToPool(*vo);
                break;
            }
            default:
                break;
        }
    }

    m_registeredEntitys[&entity] = new GNodeVOPair(node, vo);
}

void GraphicsSystem::Unregister(Entity& entity)
{
    if(m_registeredEntitys.find(&entity) == m_registeredEntitys.end())
    {
        std::cout << "There is no Entity like that in [RegisteredEntitys]\n";
        return;
    }

    delete m_registeredEntitys[&entity]->vo;
    delete m_registeredEntitys[&entity]->gn;
    m_registeredEntitys.erase(&entity);
}

void GraphicsSystem::Start() {
    m_Viewer->run();
}

GraphicsSystem::GNodeVOPair::GNodeVOPair(GraphicsNode* _gn, GraphicsEngine::ViewObject* _vo)
{
    this->gn = _gn;
    this->vo = _vo;
}
