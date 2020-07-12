#ifndef _RIVE_PATH_BASE_HPP_
#define _RIVE_PATH_BASE_HPP_
#include "node.hpp"
namespace rive
{
	class PathBase : public Node
	{
	public:
		static const int typeKey = 12;

		// Helper to quickly determine if a core object extends another without RTTI
		/// at runtime.
		bool inheritsFrom(int typeKey) override
		{
			switch (typeKey)
			{
				case NodeBase::typeKey:
				case ContainerComponentBase::typeKey:
				case ComponentBase::typeKey:
					return true;
				default:
					return false;
			}
		}

		int coreType() const override { return typeKey; }
	};
} // namespace rive

#endif