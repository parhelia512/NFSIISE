#include "Kernel32.h"

#include <SDL2/SDL_timer.h>

#ifdef WIN32
	void exit_func();
#else
	#define WAIT_TIMEOUT 0x102
	#include <sys/stat.h>
	#include <termios.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <errno.h>
#endif

#ifdef WIN32

STDCALL void *CreateThread_wrap( void *threadAttributes, uint32_t stackSize, LPTHREAD_START_ROUTINE startAddress, void *parameter, uint32_t creationFlags, uint32_t *threadId )
{
	return CreateThread( threadAttributes, stackSize, startAddress, parameter, creationFlags, ( DWORD * )threadId );
}
STDCALL uint32_t ResumeThread_wrap( HANDLE hThread )
{
	return ResumeThread( hThread );
}
STDCALL BOOL SetThreadPriority_wrap( HANDLE hThread, int priority )
{
	return SetThreadPriority( hThread, priority );
}
STDCALL uint32_t GetCurrentThreadId_wrap( void )
{
	return GetCurrentThreadId();
}
STDCALL void *GetCurrentThread_wrap( void )
{
	return GetCurrentThread();
}
STDCALL BOOL TerminateThread_wrap( HANDLE hThread, uint32_t exitCode )
{
	return TerminateThread( hThread, exitCode );
}
STDCALL void InitializeCriticalSection_wrap( CRITICAL_SECTION *criticalSection )
{
	return InitializeCriticalSection( criticalSection );
}
STDCALL void EnterCriticalSection_wrap( CRITICAL_SECTION *criticalSection )
{
	return EnterCriticalSection( criticalSection );
}
STDCALL void LeaveCriticalSection_wrap( CRITICAL_SECTION *criticalSection )
{
	return LeaveCriticalSection( criticalSection );
}
STDCALL void DeleteCriticalSection_wrap( CRITICAL_SECTION *criticalSection )
{
	return DeleteCriticalSection( criticalSection );
}
STDCALL void GlobalMemoryStatus_wrap( MEMORYSTATUS *memoryStatus )
{
	return GlobalMemoryStatus( memoryStatus );
}
STDCALL void ExitProcess_wrap( uint32_t exitCode )
{
	exit_func();
	ExitProcess( exitCode );
}
STDCALL uint32_t GetLastError_wrap( void )
{
	return GetLastError();
}
STDCALL HANDLE CreateFileA_wrap( const char *fileName, uint32_t desiredAccess, uint32_t shareMode, SECURITY_ATTRIBUTES *securityAttributes, uint32_t creationDisposition, uint32_t flagsAndAttributes, void *templateFile )
{
	return CreateFileA( fileName, desiredAccess, shareMode, securityAttributes, creationDisposition, flagsAndAttributes, templateFile );
}
STDCALL HANDLE CreateFileMappingA_wrap( HANDLE hFile, SECURITY_ATTRIBUTES *fileMappingAttributes, uint32_t flProtect, uint32_t dwMaximumSizeHigh, uint32_t dwMaximumSizeLow, const char *lpName )
{
	return CreateFileMappingA( hFile, fileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName );
}
STDCALL void *MapViewOfFile_wrap( HANDLE fMapping, uint32_t desiredAccess, uint32_t dwFileOffsetHigh, uint32_t dwFileOffsetLow, uint32_t dwNumberOfBytesToMap )
{
	return MapViewOfFile( fMapping, desiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap );
}
STDCALL BOOL UnmapViewOfFile_wrap( const void *lpBaseAddress )
{
	return UnmapViewOfFile( lpBaseAddress );
}
STDCALL BOOL FlushFileBuffers_wrap( HANDLE hFile )
{
	return FlushFileBuffers( hFile );
}
STDCALL BOOL GetOverlappedResult_wrap( HANDLE hFile, OVERLAPPED *overlapped, uint32_t *lpNumberOfBytesTransferred, BOOL bWait )
{
	return GetOverlappedResult( hFile, overlapped, ( DWORD * )lpNumberOfBytesTransferred, bWait );
}
STDCALL uint32_t GetFileSize_wrap( HANDLE hFile, uint32_t *lpFileSizeHigh )
{
	return GetFileSize( hFile, ( DWORD * )lpFileSizeHigh );
}
STDCALL BOOL SetEndOfFile_wrap( HANDLE hFile )
{
	return SetEndOfFile( hFile );
}
STDCALL uint32_t SetFilePointer_wrap( HANDLE hFile, uint32_t distanceToMove, uint32_t *distanceToMoveHigh, uint32_t moveMethod )
{
	return SetFilePointer( hFile, distanceToMove, ( LONG * )distanceToMoveHigh, moveMethod );
}
STDCALL BOOL WriteFile_wrap( HANDLE hFile, const void *buffer, uint32_t numberOfBytesToWrite, uint32_t *numberOfBytesWritten, OVERLAPPED *overlapped )
{
	return WriteFile( hFile, buffer, numberOfBytesToWrite, ( DWORD * )numberOfBytesWritten, overlapped );
}
STDCALL BOOL ReadFile_wrap( HANDLE hFile, void *buffer, uint32_t numberOfBytesToRead, uint32_t *numberOfBytesRead, OVERLAPPED *overlapped )
{
	return ReadFile( hFile, buffer, numberOfBytesToRead, ( DWORD * )numberOfBytesRead, overlapped );
}
STDCALL BOOL GetCommState_wrap( HANDLE hFile, DCB *dcb )
{
	return GetCommState( hFile, dcb );
}
STDCALL BOOL PurgeComm_wrap( HANDLE hFile, uint32_t dwFlags )
{
	return PurgeComm( hFile, dwFlags );
}
STDCALL BOOL SetCommState_wrap( HANDLE hFile, DCB *dcb )
{
	return SetCommState( hFile, dcb );
}
STDCALL BOOL SetCommTimeouts_wrap( HANDLE hFile, COMMTIMEOUTS *commTimeouts )
{
	return SetCommTimeouts( hFile, commTimeouts );
}
STDCALL BOOL DeleteFileA_wrap( const char *fileName )
{
	return DeleteFileA( fileName );
}
STDCALL void *GetModuleHandleA_wrap( const char *moduleName )
{
	return GetModuleHandleA( moduleName );
}
STDCALL BOOL CloseHandle_wrap( void *handle )
{
	return CloseHandle( handle );
}
STDCALL HANDLE CreateEventA_wrap( SECURITY_ATTRIBUTES *eventAttributes, BOOL bManualReset, BOOL bInitialState, const char *lpName )
{
	return CreateEventA( eventAttributes, bManualReset, bInitialState, lpName );
}
STDCALL BOOL SetEvent_wrap( HANDLE event )
{
	return SetEvent( event );
}
STDCALL uint32_t WaitForMultipleObjects_wrap( uint32_t nCount, void *const *lpHandles, BOOL bWaitAll, uint32_t dwMilliseconds )
{
	return WaitForMultipleObjects( nCount, lpHandles, bWaitAll, dwMilliseconds );
}
STDCALL BOOL DuplicateHandle_wrap( void *hSourceProcessHandle, void *hSourceHandle, void *hTargetProcessHandle, void **lpTargetHandle, uint32_t desiredAccess, BOOL bInheritHandle, uint32_t dwOptions )
{
	return DuplicateHandle( hSourceProcessHandle, hSourceHandle, hTargetProcessHandle, lpTargetHandle, desiredAccess, bInheritHandle, dwOptions );
}
STDCALL void *GetCurrentProcess_wrap( void )
{
	return GetCurrentProcess();
}
STDCALL void GetSystemInfo_wrap( SYSTEM_INFO *lpSystemInfo )
{
	return GetSystemInfo( lpSystemInfo );
}
STDCALL uint32_t SleepEx_wrap( uint32_t dwMilliseconds, BOOL bAlertable )
{
	return SleepEx( dwMilliseconds, bAlertable );
}
STDCALL uint32_t GetCurrentDirectoryA_wrap( uint32_t bufferLength, char *buffer )
{
	return GetCurrentDirectoryA( bufferLength, buffer );
}
STDCALL BOOL SetCurrentDirectoryA_wrap( const char *pathName )
{
	return SetCurrentDirectoryA( pathName );
}
STDCALL BOOL FindNextFileA_wrap( void *findFile, WIN32_FIND_DATAA *findFileData )
{
	return FindNextFileA( findFile, findFileData );
}
STDCALL BOOL FindClose_wrap( void *findFile )
{
	return FindClose( findFile );
}
STDCALL void *FindFirstFileA_wrap( const char *fileName, WIN32_FIND_DATAA *findFileData )
{
	return FindFirstFileA( fileName, findFileData );
}

#else /* Linux functions */

static uint32_t overlapped_error;

extern char *serialPort[ 4 ];
extern char *settingsDir;
extern SDL_mutex *event_mutex;
extern SDL_cond *event_cond;

static char *convertToUnixPath( const char *pth )
{
	uint32_t i;
	char *tmp = strdup( pth );
	for ( i = 0 ; tmp[ i ] ; ++i )
	{
		if ( tmp[ i ] == '\\' )
			tmp[ i ] = '/';
	}
	return tmp;
}

static int threadFunction( void *data )
{
	Thread *thread = ( Thread * )data;
	SDL_SemWait( thread->sem );
	SDL_DestroySemaphore( thread->sem );
	thread->threadParameter(); //In this game thread parameter is a function address
	return 0;
}

/**/

STDCALL void *CreateThread_wrap( void *threadAttributes, uint32_t stackSize, THREAD_START_ROUTINE startAddress, void *parameter, uint32_t creationFlags, uint32_t *threadId )
{
	Thread *thread = ( Thread * )malloc( sizeof( Thread ) );
	thread->handleType = HandleThread;
	thread->threadParameter = parameter;
	thread->sem = SDL_CreateSemaphore( !( creationFlags & 0x4 /*Start paused thread*/ ) );
	thread->thread = SDL_CreateThread( threadFunction, NULL, thread );
	if ( threadId )
		*threadId = SDL_GetThreadID( thread->thread );
	return thread;
}
STDCALL uint32_t ResumeThread_wrap( Thread *thread )
{
	SDL_SemPost( thread->sem );
	return 0;
}
STDCALL BOOL SetThreadPriority_wrap( Thread *thread, int priority )
{
	return false;
}
STDCALL uint32_t GetCurrentThreadId_wrap( void )
{
	return SDL_ThreadID();
}
STDCALL void *GetCurrentThread_wrap( void )
{
	return NULL;
}
STDCALL BOOL TerminateThread_wrap( Thread *thread, uint32_t exitCode )
{
	return false;
}
STDCALL void InitializeCriticalSection_wrap( CRITICAL_SECTION *criticalSection )
{
	criticalSection->mutex = SDL_CreateMutex();
}
STDCALL void EnterCriticalSection_wrap( CRITICAL_SECTION *criticalSection )
{
	SDL_LockMutex( criticalSection->mutex );
}
STDCALL void LeaveCriticalSection_wrap( CRITICAL_SECTION *criticalSection )
{
	SDL_UnlockMutex( criticalSection->mutex );
}
STDCALL void DeleteCriticalSection_wrap( CRITICAL_SECTION *criticalSection )
{
	SDL_DestroyMutex( criticalSection->mutex );
}

STDCALL void GlobalMemoryStatus_wrap( MEMORYSTATUS *memoryStatus )
{
	memset( memoryStatus, 0, sizeof( MEMORYSTATUS ) );
	memoryStatus->length = sizeof( MEMORYSTATUS );
	memoryStatus->memoryLoad = 0;
	memoryStatus->totalPhys = 0x7FFFFFFF;
	memoryStatus->totalPageFile = 0x7FFFFFFF;
	memoryStatus->availPageFile = 0x7FFFFFFF;
	memoryStatus->totalVirtual = 0x7FFFFFFF;
	memoryStatus->availVirtual = 0x7FFFFFFF;
}

STDCALL void ExitProcess_wrap( uint32_t exitCode )
{
	exit( exitCode );
}

STDCALL uint32_t GetLastError_wrap( void )
{
	if ( overlapped_error )
	{
		uint32_t e = overlapped_error;
		overlapped_error = 0;
		return e;
	}
	switch ( errno )
	{
		case ENOENT:
			return errno;
	}
	return 0;
}

STDCALL Event *CreateEventA_wrap( SECURITY_ATTRIBUTES *eventAttributes, BOOL manualReset, BOOL initialState, const char *name )
{
	Event *event = ( Event * )malloc( sizeof( Event ) );
	event->handleType = HandleEvent;
	event->manualReset = manualReset;
	event->is_set = initialState;
	return event;
}
STDCALL BOOL SetEvent_wrap( Event *event )
{
	if ( event )
	{
		SDL_LockMutex( event_mutex );
		event->is_set = true;
		SDL_CondBroadcast( event_cond );
		SDL_UnlockMutex( event_mutex );
		return true;
	}
	return false;
}
STDCALL uint32_t WaitForMultipleObjects_wrap( uint32_t count, Event *const *events, BOOL waitAll, uint32_t milliseconds )
{
	//milliseconds always -1 or 0
	//waitAll always false
	uint32_t i, ret = WAIT_TIMEOUT;
	for ( ;; )
	{
		SDL_LockMutex( event_mutex );
		for ( i = 0 ; i != count ; ++i )
		{
			if ( events[ i ]->is_set )
			{
				if ( ret == WAIT_TIMEOUT )
					ret = i;
				if ( !events[ i ]->manualReset )
					events[ i ]->is_set = false;
			}
		}
		if ( ret != WAIT_TIMEOUT || !milliseconds )
		{
			SDL_UnlockMutex( event_mutex );
			break;
		}
		if ( SDL_CondWait( event_cond, event_mutex ) == -1 ) //no timeout, because milliseconds will be always -1 here
			ret = -1;
		SDL_UnlockMutex( event_mutex );
		if ( ret == -1 )
			break;
	}
	return ret;
}

static int serialPortThread( void *data )
{
	File *file = ( File * )data;
	struct timeval tv;
	fd_set fds;
	int r;
	do
	{
		FD_ZERO( &fds );
		FD_SET( file->fd, &fds );
		tv.tv_sec = 0;
		tv.tv_usec = file->us_timeout;
		r = select( file->fd + 1, &fds, NULL, NULL, &tv );
		if ( r < 0 )
		{
			file->pending = false;
			break;
		}
		else if ( r == 1 )
		{
			uint32_t bread;
			SDL_LockMutex( file->mutex );
			bread = read( file->fd, file->asyncReadBuffer, file->toRead );
			if ( bread <= 0 )
			{
				file->pending = false;
				SDL_UnlockMutex( file->mutex );
				break;
			}
			else
			{
				if ( ( file->toRead -= bread ) )
					file->asyncReadBuffer += bread;
				else
					file->pending = false;
				file->readSoFar += bread;
			}
			SetEvent_wrap( file->readOverlapped->hEvent );
			SDL_UnlockMutex( file->mutex );
		}
	} while ( file->pending );
	return 0;
}

STDCALL File *CreateFileA_wrap( const char *fileName, uint32_t desiredAccess, uint32_t shareMode, SECURITY_ATTRIBUTES *securityAttributes, uint32_t creationDisposition, uint32_t flagsAndAttributes, void *templateFile )
{
	uint32_t COM_number = 0;
	if ( !strncasecmp( fileName, "\\\\.\\com", 7 ) )
		COM_number = fileName[ 7 ] - '0';

	char *tmpFileName = strdup( !COM_number ? fileName : serialPort[ COM_number - 1 ] );
	if ( !COM_number )
	{
		BOOL mustConvertPath = true;
		if ( settingsDir )
		{
			char fn[ 32 ];
			if ( !strncasecmp( tmpFileName, ".\\fedata\\pc\\config\\", 19 ) )
			{
				strcpy( fn, tmpFileName + 19 );
				free( tmpFileName );
				tmpFileName = ( char * )malloc( strlen( settingsDir ) + 7 + strlen( fn ) + 1 );
				strcpy( tmpFileName, settingsDir );
				strcat( tmpFileName, "config/" );
				strcat( tmpFileName, fn );
				mustConvertPath = false;
			}
			else if ( !strncasecmp( tmpFileName, ".\\fedata\\pc\\save\\", 17 ) )
			{
				strcpy( fn, tmpFileName + 17 );
				free( tmpFileName );
				tmpFileName = ( char * )malloc( strlen( settingsDir ) + 5 + strlen( fn ) + 1 );
				strcpy( tmpFileName, settingsDir );
				strcat( tmpFileName, "save/" );
				strcat( tmpFileName, fn );
				mustConvertPath = false;
			}
		}
		if ( mustConvertPath )
		{
			int i;
			for ( i = 0 ; tmpFileName[ i ] ; ++i )
			{
				if ( tmpFileName[ i ] == '\\' )
					tmpFileName[ i ] = '/';
				else
					tmpFileName[ i ] = tolower( tmpFileName[ i ] );
			}
		}
	}

	File *file = NULL;
	int fd = -1;
	switch ( desiredAccess )
	{
		case GENERIC_READ | GENERIC_WRITE: //serial port
			fd = open( tmpFileName, O_RDWR | O_NOCTTY | O_NDELAY );
			break;
		case GENERIC_WRITE:
			fd = open( tmpFileName, O_CREAT | O_WRONLY | O_TRUNC, 0644 );
			break;
		case GENERIC_READ:
			fd = open( tmpFileName, O_RDONLY );
			break;
	}
	if ( fd > 0 )
	{
		file = calloc( 1, sizeof( File ) );
		file->handleType = HandleFile;
		if ( ( file->async = !!( flagsAndAttributes & 0x40000000 /* Overlapped, async mode */ ) ) )
			file->mutex = SDL_CreateMutex();
		file->fd = fd;
	}

	free( tmpFileName );

	return file ? file : ( File * )-1;
}
STDCALL uint32_t GetFileSize_wrap( File *file, uint32_t *fileSizeHigh )
{
	struct stat stat;
	if ( !fstat( file->fd, &stat ) )
		return stat.st_size;
	return -1;
}
STDCALL FileMapping *CreateFileMappingA_wrap( File *file, SECURITY_ATTRIBUTES *fileMappingAttributes, uint32_t protect, uint32_t maximumSizeHigh, uint32_t maximumSizeLow, const char *name )
{
	FileMapping *fileMapping = ( FileMapping * )malloc( sizeof( FileMapping ) );
	fileMapping->handleType = HandleFileMapping;
	fileMapping->fd = file->fd;
	return fileMapping;
}
STDCALL void *MapViewOfFile_wrap( FileMapping *fMapping, uint32_t desiredAccess, uint32_t fileOffsetHigh, uint32_t fileOffsetLow, uint32_t numberOfBytesToMap )
{
	//Cannot use mmap() because UnmapViewOfFile doesn't provide the size. I don't want to use an array for sizes. This is also OK.
	uint32_t size = GetFileSize_wrap( ( File * )fMapping, NULL );
	void *fileMap = NULL;
	if ( size > 0 )
	{
		off_t pos = lseek( fMapping->fd, 0, SEEK_CUR );
		lseek( fMapping->fd, 0, SEEK_SET );
		fileMap = malloc( size );
		read( fMapping->fd, fileMap, size );
		lseek( fMapping->fd, pos, SEEK_SET );
	}
	return fileMap;
}
STDCALL BOOL UnmapViewOfFile_wrap( const void *lpBaseAddress )
{
	free( ( void * )lpBaseAddress );
	return true;
}
STDCALL BOOL FlusfileBuffers_wrap( File *file )
{
	return !fsync( file->fd );
}
STDCALL BOOL GetOverlappedResult_wrap( File *file, OVERLAPPED *overlapped, uint32_t *lpNumberOfBytesTransferred, BOOL bWait )
{
	if ( file->readOverlapped == overlapped )
	{
		SDL_LockMutex( file->mutex );
		*lpNumberOfBytesTransferred = file->readSoFar;
		SDL_UnlockMutex( file->mutex );
		return *lpNumberOfBytesTransferred > 0;
	}
	return false;
}
STDCALL BOOL SetEndOfFile_wrap( File *file )
{
	return !lseek( file->fd, 0, SEEK_END );
}
STDCALL uint32_t SetFilePointer_wrap( File *file, uint32_t distanceToMove, uint32_t *distanceToMoveHigh, uint32_t moveMethod )
{
	return lseek( file->fd, distanceToMove, moveMethod );
}
STDCALL BOOL WriteFile_wrap( File *file, const void *buffer, uint32_t numberOfBytesToWrite, uint32_t *numberOfBytesWritten, OVERLAPPED *overlapped )
{
	BOOL ret;
	*numberOfBytesWritten = write( file->fd, buffer, numberOfBytesToWrite );
	ret = numberOfBytesToWrite == *numberOfBytesWritten;
	if ( file->async && overlapped && overlapped->hEvent && ret )
	{
		tcdrain( file->fd );
		SetEvent_wrap( overlapped->hEvent );
	}
	return ret;
}
STDCALL BOOL ReadFile_wrap( File *file, void *buffer, uint32_t numberOfBytesToRead, uint32_t *numberOfBytesRead, OVERLAPPED *overlapped )
{
	if ( file->async )
	{
		if ( overlapped && overlapped->hEvent )
		{
			SDL_LockMutex( file->mutex );

			SDL_LockMutex( event_mutex );
			( ( Event * )overlapped->hEvent )->is_set = false;
			SDL_UnlockMutex( event_mutex );

			file->asyncReadBuffer = buffer;
			file->readOverlapped = overlapped;
			file->toRead = numberOfBytesToRead;
			file->readSoFar = 0;

			if ( file->pending )
				overlapped_error = 997; //ERROR_IO_PENDING
			else
			{
				file->pending = true;
				file->thread = SDL_CreateThread( serialPortThread, NULL, file );
			}

			SDL_UnlockMutex( file->mutex );
		}
		*numberOfBytesRead = 0;
		return false;
	}
	*numberOfBytesRead = read( file->fd, buffer, numberOfBytesToRead );
	return *numberOfBytesRead == numberOfBytesToRead;
}
STDCALL BOOL GetCommState_wrap( File *file, DCB *dcb )
{
	return true;
}
STDCALL BOOL PurgeComm_wrap( File *file, uint32_t flags )
{
	if ( flags & 0x5 )
		tcflush( file->fd, TCOFLUSH );
	if ( flags & 0xA )
		tcflush( file->fd, TCIFLUSH );
	return true;
}
STDCALL BOOL SetCommState_wrap( File *file, DCB *dcb )
{
	struct termios tty;
	memset( &tty, 0, sizeof( struct termios ) );
	cfsetospeed( &tty, B9600 );
	cfsetispeed( &tty, B9600 );
	tty.c_cflag |= CS8 | CLOCAL | CREAD;
	return !tcsetattr( file->fd, TCSANOW, &tty );
}
STDCALL BOOL SetCommTimeouts_wrap( File *file, COMMTIMEOUTS *commTimeouts )
{
	file->us_timeout = commTimeouts->ReadTotalTimeoutConstant * 1000;
	return true;
}

STDCALL BOOL DeleteFileA_wrap( const char *fileName )
{
	char *tmpFileName;
	BOOL ret;
	if ( !settingsDir || strncasecmp( fileName, ".\\fedata\\pc\\save\\", 17 ) )
		tmpFileName = convertToUnixPath( fileName );
	else
	{
		tmpFileName = ( char * )malloc( strlen( settingsDir ) + 5 + strlen( fileName + 17 ) + 1 );
		strcpy( tmpFileName, settingsDir );
		strcat( tmpFileName, "save/" );
		strcat( tmpFileName, fileName + 17 );
	}
	ret = !unlink( tmpFileName );
	free( tmpFileName );
	return ret;
}

STDCALL void *GetModuleHandleA_wrap( const char *moduleName )
{
	return NULL;
}
STDCALL BOOL CloseHandle_wrap( void *handle )
{
	if ( !handle )
		return false;
	switch ( *( HandleType * )handle )
	{
		case HandleThread:
		{
			Thread *thread = ( Thread * )handle;
			free( thread );
			return true;
		}
		case HandleFile:
		{
			File *file = ( File * )handle;
			close( file->fd );
			SDL_WaitThread( file->thread, NULL );
			SDL_DestroyMutex( file->mutex );
			free( file );
			return true;
		}
		case HandleFileMapping:
		{
			FileMapping *fMapping = ( FileMapping * )handle;
			free( fMapping );
			return true;
		}
		case HandleEvent:
		{
			Event *event = ( Event * )handle;
			free( event );
			return true;
		}
	}
	return false;
}

STDCALL BOOL DuplicateHandle_wrap( void *hSourceProcessHandle, void *hSourceHandle, void *hTargetProcessHandle, void **lpTargetHandle, uint32_t desiredAccess, BOOL bInheritHandle, uint32_t dwOptions )
{
	*lpTargetHandle = NULL;
	return false;
}

STDCALL void *GetCurrentProcess_wrap( void )
{
	return NULL;
}

STDCALL void GetSystemInfo_wrap( SYSTEM_INFO *systemInfo )
{
	memset( systemInfo, 0, sizeof( SYSTEM_INFO ) );
	systemInfo->pageSize = getpagesize();
}
STDCALL uint32_t SleepEx_wrap( uint32_t milliseconds, BOOL alertable )
{
	SDL_Delay( milliseconds );
	return 0;
}

STDCALL uint32_t GetCurrentDirectoryA_wrap( uint32_t bufferLength, char *buffer )
{
	if ( getcwd( buffer, bufferLength ) )
		return bufferLength;
	return 0;
}
STDCALL BOOL SetCurrentDirectoryA_wrap( const char *pathName )
{
	char *tmpPathName;
	BOOL ret;
	if ( !settingsDir || strcasecmp( pathName, ".\\fedata\\pc\\save\\" ) )
		tmpPathName = convertToUnixPath( pathName );
	else
	{
		tmpPathName = ( char * )malloc( strlen( settingsDir ) + 5 + 1 );
		strcpy( tmpPathName, settingsDir );
		strcat( tmpPathName, "save/" );
	}
	ret = !chdir( tmpPathName );
	free( tmpPathName );
	return ret;
}

STDCALL BOOL FindNextFileA_wrap( FindFile *findFile, WIN32_FIND_DATA *findFileData )
{
	struct dirent *de;
	int pos;
	while ( ( de = readdir( findFile->dir ) ) )
	{
		if ( *de->d_name == '.' || de->d_type == DT_DIR )
			continue;
		pos = strlen( de->d_name ) - strlen( findFile->filter + 1 );
		if ( pos < 0 || strcasecmp( de->d_name + pos, findFile->filter + 1 ) )
			continue;
		strcpy( findFileData->fileName, de->d_name );
		return true;
	}
	return false;
}
STDCALL BOOL FindClose_wrap( FindFile *findFile )
{
	if ( findFile )
	{
		if ( findFile->dir )
			closedir( findFile->dir );
		free( findFile->filter );
		free( findFile );
		return true;
	}
	return false;
}
STDCALL FindFile *FindFirstFileA_wrap( const char *fileName, WIN32_FIND_DATA *findFileData )
{
	memset( findFileData, 0, sizeof( WIN32_FIND_DATA ) );

	if ( *fileName != '*' ) //It should be always false
		return ( FindFile * )-1;

	DIR *dir = opendir( "." );
	if ( !dir )
		return ( FindFile * )-1;

	FindFile *findFile = ( FindFile * )malloc( sizeof( FindFile ) );
	findFile->dir = dir;
	findFile->filter = strdup( fileName );

	if ( !FindNextFileA_wrap( findFile, findFileData ) )
	{
		FindClose_wrap( findFile );
		return ( FindFile * )-1;
	}

	return findFile;
}

#endif

/* Common functions */

STDCALL uint32_t GetFileAttributesA_wrap( const char *fileName )
{
	return 0;
}
STDCALL BOOL SetFileAttributesA_wrap( const char *fileName, uint32_t fileAttributes )
{
	return false;
}