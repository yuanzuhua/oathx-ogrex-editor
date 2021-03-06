#ifndef _____OgreWorld_H
#define _____OgreWorld_H

namespace Ogre
{
	// world create adapter param
	struct SWorldAdp : public SSAdp
	{
		SceneTypeMask	typeMask;
		ColourValue		clrAmbientLight;
	};

	/**
	* \ingroup : OgreSandBox
	*
	* \os&IDE  : Microsoft Windows XP (SP3)  &  Microsoft Visual C++ .NET 2008
	*
	* \VERSION : 1.0
	*
	* \date    : 2013-06-06
	*
	* \Author  : lp
	*
	* \Desc    : sand box world
	*
	* \bug     : 
	*
	* \Copyright (c) 2012 lp All rights reserved.
	*/
	class Ogre_SandBox_Export_API WorldServer : public Server
	{
	public:
		static const String		EventNamespace;
		static const String		ServerTypeName;
	public:
		/**
		 *
		 * \param nID 
		 * \return 
		 */
		WorldServer(const uint32 nID, const String& szName);

		/**
		 *
		 * \return 
		 */
		virtual ~WorldServer();

	public:
		/**
		 *
		 * \return 
		 */
		virtual	SceneManager*	getSceneManager() const;

		/**
		 *
		 * \return 
		 */
		virtual RaySceneQuery*	getRaySceneQuery() const;

	public:
		/**
		 *
		 * \param ssadp 
		 * \return 
		 */
		virtual	bool			configure(const SSAdp& ssadp);
	protected:
		SceneManager*			m_pSceneManager;
		RaySceneQuery*			m_pSceneQuery;
	};

	/**
	* \ingroup : OgreSandBox
	*
	* \os&IDE  : Microsoft Windows XP (SP3)  &  Microsoft Visual C++ .NET 2008
	*
	* \VERSION : 1.0
	*
	* \date    : 2013-06-06
	*
	* \Author  : lp
	*
	* \Desc    : 
	*
	* \bug     : 
	*
	* \Copyright (c) 2012 lp All rights reserved.
	*/
	class Ogre_SandBox_Export_API WorldServerFactory : public ServerFactory
	{
	public:
		/**
		 *
		 * \param typeName 
		 * \return 
		 */
		WorldServerFactory(const String& typeName)
			: ServerFactory(typeName)
		{

		}

		/**
		 *
		 * \return 
		 */
		virtual ~WorldServerFactory()
		{

		}

		/**
		 *
		 * \param nID 
		 * \param szName 
		 * \param ssadp 
		 * \param pParent 
		 * \return 
		 */
		virtual Server*			createServer(const uint32 nID, const String& szName, const SSAdp& ssadp, Server* pParent)
		{
			WorldServer* pWorld = new WorldServer(nID, szName);
			try{
				if (pWorld->configure(ssadp))
				{
					if (pParent)
						pParent->registerServer(pWorld);

					return pWorld;
				}
				else
				{
					OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED, "Crate server " + szName + " error",
						"WorldFactory::createServer");
				}
			}
			catch(Exception& e)
			{
				TKLogEvent(e.getFullDescription().c_str(), 
					LML_CRITICAL);

				delete pWorld;
			}

			return NULL;
		}
	};
}

#endif