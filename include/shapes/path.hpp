#ifndef _RIVE_PATH_HPP_
#define _RIVE_PATH_HPP_
#include "generated/shapes/path_base.hpp"
#include "math/mat2d.hpp"
#include <vector>

namespace rive
{
	class Shape;
	class RenderPath;
	class PathVertex;

	class Path : public PathBase
	{
	protected:
		Shape* m_Shape = nullptr;
		RenderPath* m_RenderPath = nullptr;
		std::vector<PathVertex*> m_Vertices;

	public:
		~Path();
		Shape* shape() const { return m_Shape; }
		StatusCode onAddedDirty(CoreContext* context) override;
		StatusCode onAddedClean(CoreContext* context) override;
		virtual const Mat2D& pathTransform() const;
		RenderPath* renderPath() const { return m_RenderPath; }
		void update(ComponentDirt value) override;

		void addVertex(PathVertex* vertex);

		virtual void markPathDirty();
		virtual bool isPathClosed() const { return true; }

#ifdef TESTING
		std::vector<PathVertex*>& vertices() { return m_Vertices; }
#endif
	};
} // namespace rive

#endif