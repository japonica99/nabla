#ifndef _NABLA_CORE_PRMITIVE_COMPONENT_H_
#define _NABLA_CORE_PRMITIVE_COMPONENT_H_

#include "core/entity.h"
#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"

namespace nabla {

struct RigidBody {
	glm::vec3 position = glm::vec3(0.0f);
	glm::vec3 scale = glm::vec3(1.0f);
	glm::quat quaternion;
};

}

#endif