#include "material.h"
#include "editor/gui.h"

namespace nabla {
	
void MatrialSysterm::SetUpMaterialHandles(renderer::ShaderHandle shader, MatrialSysterm::Uniforms names)
{
	using namespace renderer;
#define GET_UNIFORM(name, type, ...) \
	h##name##_ = renderer::NewUniform(shader, names.##name, renderer::MaterialType::k##type); \
	NA_LEAVE_IF((void) 0, h##name##_.IsNil(), "Invalid Hanlde"); 

	NA_BUILTIN_MATERIAL_SYS_LIST(GET_UNIFORM)
#undef GET_UNIFORM
}

void MatrialSysterm::Add(Entity e, Material material)
{
	sparse_.size_at_least(e.index(), Entity::kInvalidIndex);
	sparse_[e.index()] = dense_.size();
	dense_.push_back(material);
}

void MatrialSysterm::OnGui(const Vector<Entity>& actives)
{
	for (auto e : actives) {
		if (!Has(e)) {
			return;
		}

		auto& m = dense_[sparse_[e.index()]];

		ImGui::ColorEdit3("Diffuse", &m.diffuse[0]);
		ImGui::DragFloat("Specular", &m.specular, 0.01, -1.0f, 2.0f);
		

		ImGui::Text("Physically Based Rendering");
		ImGui::ColorEdit3("Albedo", &m.albedo[0]);
		ImGui::DragFloat("Metallic", &m.metallic, 0.01, 0.0f, 1.0f);
		ImGui::DragFloat("Roughness", &m.roughness, 0.01, 0.0f, 1.0f);
		ImGui::DragFloat("Ambient Occulison", &m.ambient_occulsion, 0.1f);
	}
}



void MatrialSysterm::Update(Entity e)
{
#define SET_UNI(name, ...) renderer::SetUniform(h##name##_, dense_[sparse_[e.index()]].##name);
	NA_BUILTIN_MATERIAL_SYS_LIST(SET_UNI)
#undef SET_UNI
}



}