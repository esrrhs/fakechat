/* This file is generated by genxml. */
/* No manual modification is permitted. */

#pragma once









class CConfigLoader
{
public:
	struct STConfig
	{
		STConfig()
		{
			
		}
		
		struct STFriendList
		{
			STFriendList()
			{
				
			}
			
			struct STFriend
			{
				STFriend()
				{
					
					m_stracc.clear();
					
					m_strip.clear();
					
					m_strkey.clear();
					
					m_strname.clear();
					
					m_iport = 0;
					
				}
				
				std::string m_stracc;
				
				std::string m_strip;
				
				std::string m_strkey;
				
				std::string m_strname;
				
				int32_t m_iport;
				

			};
			
			
			std::vector<STFriend> m_vecSTFriend;

		};
		
		STFriendList m_STFriendList;
		struct STSTUNServer
		{
			STSTUNServer()
			{
				
			}
			
			struct STSTUN
			{
				STSTUN()
				{
					
					m_strip.clear();
					
				}
				
				std::string m_strip;
				

			};
			
			
			std::vector<STSTUN> m_vecSTSTUN;

		};
		
		STSTUNServer m_STSTUNServer;
		struct STUser
		{
			STUser()
			{
				
				m_stracc.clear();
				
				m_strname.clear();
				
				m_iport = 0;
				
				m_strpwd.clear();
				
			}
			
			std::string m_stracc;
			
			std::string m_strname;
			
			int32_t m_iport;
			
			std::string m_strpwd;
			

		};
		
		STUser m_STUser;

	};
	
	STConfig & GetConfig()
	{
		return m_STConfig;
	}
	
	bool LoadCfg(const std::string & file)
	{
		TiXmlDocument document;
		if (!document.LoadFile((const char*)file.c_str()))
		{
			LCERR("CConfigLoader::LoadCfg(%s) failed", (const char*)file.c_str());
			return false;
		}
		
		TiXmlElement* pConfig = document.RootElement();
		if (!pConfig)
		{
			LCERR("document.RootElement failed");
			return false;
		}
		
		// clear
		STConfig tmp;
		m_STConfig = tmp;
		
		
		
		
		TiXmlNode * pFriendList = pConfig->FirstChild("FriendList");
		if (pFriendList)
		{
			
			STConfig::STFriendList tmpFriendList;
			
			
			for (TiXmlNode * pFriend = pFriendList->FirstChild("Friend"); NULL != pFriend; pFriend = pFriend->NextSibling("Friend"))
			{
			
				STConfig::STFriendList::STFriend tmpFriend;
				
				tmpFriend.m_stracc = ((TiXmlElement *)pFriend)->Attribute("acc");
				LCLOG("			acc %s", tmpFriend.m_stracc.c_str());
				
				tmpFriend.m_strip = ((TiXmlElement *)pFriend)->Attribute("ip");
				LCLOG("			ip %s", tmpFriend.m_strip.c_str());
				
				tmpFriend.m_strkey = ((TiXmlElement *)pFriend)->Attribute("key");
				LCLOG("			key %s", tmpFriend.m_strkey.c_str());
				
				tmpFriend.m_strname = ((TiXmlElement *)pFriend)->Attribute("name");
				LCLOG("			name %s", tmpFriend.m_strname.c_str());
				
				((TiXmlElement *)pFriend)->Attribute("port", &tmpFriend.m_iport);
				LCLOG("			port %d", tmpFriend.m_iport);
				
				

				tmpFriendList.m_vecSTFriend.push_back(tmpFriend);
			}

			m_STConfig.m_STFriendList = tmpFriendList;
		}
		TiXmlNode * pSTUNServer = pConfig->FirstChild("STUNServer");
		if (pSTUNServer)
		{
			
			STConfig::STSTUNServer tmpSTUNServer;
			
			
			for (TiXmlNode * pSTUN = pSTUNServer->FirstChild("STUN"); NULL != pSTUN; pSTUN = pSTUN->NextSibling("STUN"))
			{
			
				STConfig::STSTUNServer::STSTUN tmpSTUN;
				
				tmpSTUN.m_strip = ((TiXmlElement *)pSTUN)->Attribute("ip");
				LCLOG("			ip %s", tmpSTUN.m_strip.c_str());
				
				

				tmpSTUNServer.m_vecSTSTUN.push_back(tmpSTUN);
			}

			m_STConfig.m_STSTUNServer = tmpSTUNServer;
		}
		TiXmlNode * pUser = pConfig->FirstChild("User");
		if (pUser)
		{
			
			STConfig::STUser tmpUser;
			
			tmpUser.m_stracc = ((TiXmlElement *)pUser)->Attribute("acc");
			LCLOG("		acc %s", tmpUser.m_stracc.c_str());
			
			tmpUser.m_strname = ((TiXmlElement *)pUser)->Attribute("name");
			LCLOG("		name %s", tmpUser.m_strname.c_str());
			
			((TiXmlElement *)pUser)->Attribute("port", &tmpUser.m_iport);
			LCLOG("		port %d", tmpUser.m_iport);
			
			tmpUser.m_strpwd = ((TiXmlElement *)pUser)->Attribute("pwd");
			LCLOG("		pwd %s", tmpUser.m_strpwd.c_str());
			
			

			m_STConfig.m_STUser = tmpUser;
		}
		
		return true;
	}
	
	bool SaveCfg(const std::string & file)
	{
		TiXmlDocument document;
		
		TiXmlElement tmpXmlConfig("Config");
		
		
		
		
		
		{
			STConfig::STFriendList & tmpFriendList =  m_STConfig.m_STFriendList;
			TiXmlElement * pFather = &tmpXmlConfig;
			
			TiXmlElement tmpXmlFriendList("FriendList");
			
			
			for (int i = 0; i < (int)tmpFriendList.m_vecSTFriend.size(); i++)
			{
				STConfig::STFriendList::STFriend & tmpFriend = tmpFriendList.m_vecSTFriend[i];
				TiXmlElement * pFather = &tmpXmlFriendList;
			
				TiXmlElement tmpXmlFriend("Friend");
				
				tmpXmlFriend.SetAttribute("acc", tmpFriend.m_stracc.c_str());
				LCLOG("			acc %s", tmpFriend.m_stracc.c_str());
				
				tmpXmlFriend.SetAttribute("ip", tmpFriend.m_strip.c_str());
				LCLOG("			ip %s", tmpFriend.m_strip.c_str());
				
				tmpXmlFriend.SetAttribute("key", tmpFriend.m_strkey.c_str());
				LCLOG("			key %s", tmpFriend.m_strkey.c_str());
				
				tmpXmlFriend.SetAttribute("name", tmpFriend.m_strname.c_str());
				LCLOG("			name %s", tmpFriend.m_strname.c_str());
				
				tmpXmlFriend.SetAttribute("port", tmpFriend.m_iport);
				LCLOG("			port %d", tmpFriend.m_iport);
				
				
				pFather->InsertEndChild(tmpXmlFriend);

			}
			
			pFather->InsertEndChild(tmpXmlFriendList);

		}
		
		{
			STConfig::STSTUNServer & tmpSTUNServer =  m_STConfig.m_STSTUNServer;
			TiXmlElement * pFather = &tmpXmlConfig;
			
			TiXmlElement tmpXmlSTUNServer("STUNServer");
			
			
			for (int i = 0; i < (int)tmpSTUNServer.m_vecSTSTUN.size(); i++)
			{
				STConfig::STSTUNServer::STSTUN & tmpSTUN = tmpSTUNServer.m_vecSTSTUN[i];
				TiXmlElement * pFather = &tmpXmlSTUNServer;
			
				TiXmlElement tmpXmlSTUN("STUN");
				
				tmpXmlSTUN.SetAttribute("ip", tmpSTUN.m_strip.c_str());
				LCLOG("			ip %s", tmpSTUN.m_strip.c_str());
				
				
				pFather->InsertEndChild(tmpXmlSTUN);

			}
			
			pFather->InsertEndChild(tmpXmlSTUNServer);

		}
		
		{
			STConfig::STUser & tmpUser =  m_STConfig.m_STUser;
			TiXmlElement * pFather = &tmpXmlConfig;
			
			TiXmlElement tmpXmlUser("User");
			
			tmpXmlUser.SetAttribute("acc", tmpUser.m_stracc.c_str());
			LCLOG("		acc %s", tmpUser.m_stracc.c_str());
			
			tmpXmlUser.SetAttribute("name", tmpUser.m_strname.c_str());
			LCLOG("		name %s", tmpUser.m_strname.c_str());
			
			tmpXmlUser.SetAttribute("port", tmpUser.m_iport);
			LCLOG("		port %d", tmpUser.m_iport);
			
			tmpXmlUser.SetAttribute("pwd", tmpUser.m_strpwd.c_str());
			LCLOG("		pwd %s", tmpUser.m_strpwd.c_str());
			
			
			pFather->InsertEndChild(tmpXmlUser);

		}
		
		document.InsertEndChild(tmpXmlConfig);
		
		if (!document.SaveFile((const char*)file.c_str()))
		{
			LCERR("CConfigLoader::SaveCfg(%s) failed", (const char*)file.c_str());
			return false;
		}
		
		return true;
	}
	
private:
	STConfig m_STConfig;
};

extern CConfigLoader g_CConfigLoader;