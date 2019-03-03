#pragma once
#include <map>
#include <string>
#include <iostream>

using namespace std;
template<typename T>
class AssetFile
{
public:
	void SetFile(const T& data, const string& fileName)
	{
		m_sFileName = fileName;
		m_tFileData = data;
		m_iHashsedFileName = hash<std::string>()(fileName);
	}

	int GetHashedFileName() const { return m_iHashsedFileName; } 
	string GetFileName() const { return m_sFileName; }
	T GetFileData() { return m_tFileData; }

private:
	string m_sFileName = "";
	int m_iHashsedFileName = 0;
	T m_tFileData;
};

template <typename T>
class AssetPool
{
public:

	template <typename First, typename... Arguments> 
	int AddFilesToPool(const First& first, const Arguments&... args)
	{
		int res = AddFileToPool(first);
		AddFilesToPool(args...);
		return res;
	}

	template <typename First, typename... Arguments>
	int RemoveFilesFromPool(const First& first, const Arguments&... args)
	{
		int res = RemoveFileFromPool(first);
		RemoveFilesFromPool(args...);
		return res;
	}

	unsigned short GetAssetId(string filename)
	{
		int hashedName = hash<std::string>()(filename);

		for (auto const& x : m_mPool)
		{
			if (x.second.GetHashedFileName() == hashedName)
			{
				return x.first;
			}
		}

		return NULL;
	}

	AssetFile<T> GetAssetById(unsigned short id)
	{
		for (auto const& x : m_mPool)
		{
			if (x.first == id)
			{
				return x.second;
			}
		}

		return AssetFile<T>();
	}

	AssetFile<T> GetAssetByFilename(string filename)
	{
		int hashedName = hash<std::string>()(filename);

		for (auto const& x : m_mPool)
		{
			if (x.second.GetHashedFileName() == hashedName)
			{
				return x.second;
			}
		}

		return AssetFile<T>();
	}

	void ClearPool()
	{
		m_mPool.clear();
	}

private:
	int AddFilesToPool()
	{
		return 1;
	}

	int RemoveFilesFromPool()
	{
		return 1;
	}

	int AddFileToPool(const AssetFile<T>& file)
	{
		if (DoesFileExistInPool(file))
		{
			cout << "File " << file.GetFileName() << " already exists in asset pool." << endl;
			return -1;
		}

		InsertFileIntoPool(file);

		return 1;
	}

	int RemoveFileFromPool(int id)
	{
		if (!DoesIdExistInPool(id))
		{
			cout << "File with id: " << id << " does not exist in asset pool and so cannot be deleted." << endl;
			return -1;
		}

		auto it = m_mPool.find(id);
		m_mPool.erase(it);

		return 1;
	}

	bool DoesFileExistInPool(const AssetFile<T>& file)
	{
		for (auto const& x : m_mPool)
		{
			if (x.second.GetHashedFileName() == file.GetHashedFileName())
			{
				return true;
			}
		}

		return false;
	}

	bool DoesIdExistInPool(int id)
	{
		for (auto const& x : m_mPool)
		{
			if (x.first == id)
			{
				return true;
			}
		}

		return false;
	}

	void InsertFileIntoPool(const AssetFile<T>& file)
	{
		m_mPool.insert(pair<unsigned char, AssetFile<T>>(idTracker, file));
		++idTracker;
	}

	int idTracker = 0;
	map<unsigned char, AssetFile<T>> m_mPool;
};