//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#pragma mark Blocks

typedef void (^CDUnknownBlockType)(void); // return type and parameters are unknown

#pragma mark -

//
// File: /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/System/Library/PrivateFrameworks/ToneLibrary.framework/ToneLibrary
// UUID: A25CFBE7-8E24-37CD-9BBB-20F517B24CBE
//
//                           Arch: x86_64
//                Current version: 1.0.0
//          Compatibility version: 1.0.0
//                 Source version: 252.0.0.0.0
//            Minimum iOS version: 8.0.0
//                    SDK version: 8.0.0
//
// Objective-C Garbage Collection: Unsupported
//

@protocol NSObject
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;
@property(readonly) unsigned long long hash;
- (struct _NSZone *)zone;
- (unsigned long long)retainCount;
- (id)autorelease;
- (oneway void)release;
- (id)retain;
- (_Bool)respondsToSelector:(SEL)arg1;
- (_Bool)conformsToProtocol:(Protocol *)arg1;
- (_Bool)isMemberOfClass:(Class)arg1;
- (_Bool)isKindOfClass:(Class)arg1;
- (_Bool)isProxy;
- (id)performSelector:(SEL)arg1 withObject:(id)arg2 withObject:(id)arg3;
- (id)performSelector:(SEL)arg1 withObject:(id)arg2;
- (id)performSelector:(SEL)arg1;
- (id)self;
- (Class)class;
- (_Bool)isEqual:(id)arg1;

@optional
@property(readonly, copy) NSString *debugDescription;
@end

@protocol TLServiceAgentInterface <NSObject>
- (void)removeAllUserGeneratedVibrationPatternsWithCompletionHandler:(void (^)(_Bool, NSError *))arg1;
- (void)setUserGeneratedVibrationPatterns:(NSDictionary *)arg1 withCompletionHandler:(void (^)(_Bool, NSError *))arg2;
- (void)retrieveUserGeneratedVibrationPatternsWithCompletionHandler:(void (^)(NSDictionary *, NSError *))arg1;
- (void)setCurrentToneIdentifier:(NSString *)arg1 forPreferenceKey:(NSString *)arg2 completionHandler:(void (^)(_Bool, NSError *))arg3;
- (void)retrieveCurrentTonePreferencesWithCompletionHandler:(void (^)(NSDictionary *, NSError *))arg1;
@end

@interface NSError (TLExtensions)
+ (id)tl_errorWithDomain:(id)arg1 description:(id)arg2;
- (id)tl_nonRedundantDescription;
@end

@interface TLAccessQueue : NSObject
{
    NSString *_label;
    NSString *_threadLocalStorageKey;
    NSObject<OS_dispatch_queue> *_serialQueue;
}

@property(nonatomic, setter=_setSerialQueue:) NSObject<OS_dispatch_queue> *_serialQueue; // @synthesize _serialQueue;
@property(copy, nonatomic, setter=_setThreadLocalStorageKey:) NSString *_threadLocalStorageKey; // @synthesize _threadLocalStorageKey;
- (void)_setLabel:(id)arg1;
@property(copy, nonatomic) NSString *label; // @synthesize label=_label;
- (void)_performSynchronousBlockInSerialQueue:(CDUnknownBlockType)arg1;
- (void)performAsynchronousBlock:(CDUnknownBlockType)arg1;
- (void)performSynchronousBlock:(CDUnknownBlockType)arg1;
- (void)dealloc;
- (id)initWithLabel:(id)arg1 appendUUIDToLabel:(_Bool)arg2;

@end

@interface TLAlert : NSObject
{
    _Bool _shouldOverrideMasterSwitches;
    int _type;
    NSString *_toneIdentifier;
    NSString *_vibrationIdentifier;
    NSObject<OS_dispatch_queue> *_targetQueue;
    CDUnknownBlockType _completionHandler;
    NSTimer *_completionFallbackTimer;
}

+ (void)_playToneAndVibrationForType:(int)arg1 toneIdentifier:(id)arg2 vibrationIdentifier:(id)arg3 shouldOverrideMasterSwitches:(_Bool)arg4;
+ (void)playToneAndVibrationForType:(int)arg1 toneIdentifier:(id)arg2 vibrationIdentifier:(id)arg3;
+ (void)playToneAndVibrationForType:(int)arg1 accountIdentifier:(id)arg2;
+ (void)playToneAndVibrationForType:(int)arg1;
@property(retain, nonatomic, setter=_setCompletionFallbackTimer:) NSTimer *_completionFallbackTimer; // @synthesize _completionFallbackTimer;
@property(copy, nonatomic, setter=_setCompletionHandler:) CDUnknownBlockType _completionHandler; // @synthesize _completionHandler;
@property(nonatomic, setter=_setTargetQueue:) NSObject<OS_dispatch_queue> *_targetQueue; // @synthesize _targetQueue;
@property(nonatomic, setter=_setShouldOverrideMasterSwitches:) _Bool _shouldOverrideMasterSwitches; // @synthesize _shouldOverrideMasterSwitches;
- (void)_setVibrationIdentifier:(id)arg1;
@property(copy, nonatomic) NSString *vibrationIdentifier; // @synthesize vibrationIdentifier=_vibrationIdentifier;
- (void)_setToneIdentifier:(id)arg1;
@property(copy, nonatomic) NSString *toneIdentifier; // @synthesize toneIdentifier=_toneIdentifier;
- (void)_setType:(int)arg1;
@property(nonatomic) int type; // @synthesize type=_type;
- (void)stop;
- (_Bool)playWithCompletionHandler:(CDUnknownBlockType)arg1 targetQueue:(id)arg2;
- (void)dealloc;
- (id)initWithType:(int)arg1 toneIdentifier:(id)arg2 vibrationIdentifier:(id)arg3;
- (id)initWithType:(int)arg1 accountIdentifier:(id)arg2;
- (id)initWithType:(int)arg1;

@end

@interface TLAlertController : NSObject
{
    NSMutableDictionary *_alertsBySoundIDs;
    TLAccessQueue *_alertsBySoundIDsAccessQueue;
}

+ (id)sharedAlertController;
@property(retain, setter=_setAlertsBySoundIDsAccessQueue:) TLAccessQueue *_alertsBySoundIDsAccessQueue; // @synthesize _alertsBySoundIDsAccessQueue;
@property(retain, nonatomic, setter=_setAlertsBySoundIDs:) NSMutableDictionary *_alertsBySoundIDs; // @synthesize _alertsBySoundIDs;
@property(readonly, nonatomic) _Bool _hasVibratorCapability;
- (void)_didReachTimeoutForSystemSound:(id)arg1;
- (void)_systemSoundDidFinishPlaying:(unsigned int)arg1;
- (void)_removeSoundID:(unsigned int)arg1 shouldStopSound:(_Bool)arg2 fireCompletionHandler:(_Bool)arg3;
- (_Bool)_stopAllAlerts;
- (unsigned int)_soundIDForAlert:(id)arg1;
- (void)_stopAlert:(id)arg1;
- (_Bool)_playAlert:(id)arg1 completionHandler:(CDUnknownBlockType)arg2 targetQueue:(id)arg3;
- (_Bool)stopAllAlerts;
- (void)dealloc;
- (id)init;

@end

@interface TLAlertTone : NSObject
{
    NSString *_filePath;
    TLSound *_actualSound;
    TLSound *_previewSound;
}

- (void)_setPreviewSound:(id)arg1;
@property(retain, nonatomic) TLSound *previewSound; // @synthesize previewSound=_previewSound;
- (void)_setActualSound:(id)arg1;
@property(retain, nonatomic) TLSound *actualSound; // @synthesize actualSound=_actualSound;
- (void)_setFilePath:(id)arg1;
@property(copy, nonatomic) NSString *filePath; // @synthesize filePath=_filePath;
- (void)dealloc;
- (id)initWithFilePath:(id)arg1 actualSoundID:(unsigned int)arg2 previewSoundID:(unsigned int)arg3;

@end

@interface TLITunesTone : NSObject
{
    _Bool _purchased;
    _Bool _ringtone;
    _Bool _protected;
    _Bool _private;
    NSString *_identifier;
    NSString *_name;
    NSString *_filePath;
    NSNumber *_pid;
    NSString *_artworkFile;
    unsigned long long _duration;
    NSDictionary *_playbackProperties;
}

- (void)_setPlaybackProperties:(id)arg1;
@property(copy, nonatomic) NSDictionary *playbackProperties; // @synthesize playbackProperties=_playbackProperties;
- (void)_setPrivate:(_Bool)arg1;
@property(nonatomic, getter=isPrivate) _Bool private; // @synthesize private=_private;
- (void)_setProtected:(_Bool)arg1;
@property(nonatomic, getter=isProtected) _Bool protected; // @synthesize protected=_protected;
- (void)_setDuration:(unsigned long long)arg1;
@property(nonatomic) unsigned long long duration; // @synthesize duration=_duration;
- (void)_setArtworkFile:(id)arg1;
@property(copy, nonatomic) NSString *artworkFile; // @synthesize artworkFile=_artworkFile;
- (void)_setPid:(id)arg1;
@property(copy, nonatomic) NSNumber *pid; // @synthesize pid=_pid;
- (void)_setRingtone:(_Bool)arg1;
@property(nonatomic, getter=isRingtone) _Bool ringtone; // @synthesize ringtone=_ringtone;
- (void)_setPurchased:(_Bool)arg1;
@property(nonatomic, getter=isPurchased) _Bool purchased; // @synthesize purchased=_purchased;
- (void)_setFilePath:(id)arg1;
@property(copy, nonatomic) NSString *filePath; // @synthesize filePath=_filePath;
- (void)_setName:(id)arg1;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;
- (void)_setIdentifier:(id)arg1;
@property(copy, nonatomic) NSString *identifier; // @synthesize identifier=_identifier;
- (void)dealloc;
- (id)initWithPropertyListRepresentation:(id)arg1 filePath:(id)arg2;

@end

@interface TLSound : NSObject
{
    _Bool _shouldDisposeOfSoundID;
    unsigned int _soundID;
    NSString *_filePath;
}

- (void)_setSoundID:(unsigned int)arg1;
@property(nonatomic, setter=_setShouldDisposeOfSoundID:) _Bool _shouldDisposeOfSoundID; // @synthesize _shouldDisposeOfSoundID;
- (void)_setFilePath:(id)arg1;
@property(copy, nonatomic) NSString *filePath; // @synthesize filePath=_filePath;
@property(nonatomic) unsigned int soundID; // @synthesize soundID=_soundID;
- (void)dealloc;
- (id)initWithFilePath:(id)arg1 soundID:(unsigned int)arg2;

@end

@interface TLToneManager : NSObject
{
    _Bool _shouldUseServiceToAccessTonePreferences;
    _Bool _shouldIgnoreNextToneDidChangeNotification;
    NSMutableDictionary *_iTunesTonesByIdentifier;
    NSMutableDictionary *_iTunesToneIdentifiersByPID;
    NSMutableDictionary *_alertTonesByIdentifier;
    NSDictionary *_toneIdentifierAliasMap;
    NSDictionary *_previewBehaviorsByDefaultIdentifier;
    NSDictionary *_cachedTonePreferences;
    TLAccessQueue *_accessQueue;
}

+ (struct __CFString *)_copySharedResourcesPreferencesDomainForDomain:(struct __CFString *)arg1;
+ (_Bool)_migrateLegacyToneSettings;
+ (id)_defaultToneIdentifierForAlertType:(int)arg1;
+ (id)_copySystemWideTonePreferenceKeyForAlertType:(int)arg1 accountIdentifier:(id)arg2;
+ (id)sharedToneManager;
@property(retain, setter=_setAccessQueue:) TLAccessQueue *_accessQueue; // @synthesize _accessQueue;
@property(nonatomic, setter=_setShouldIgnoreNextToneDidChangeNotification:) _Bool _shouldIgnoreNextToneDidChangeNotification; // @synthesize _shouldIgnoreNextToneDidChangeNotification;
@property(retain, nonatomic, setter=_setCachedTonePreferences:) NSDictionary *_cachedTonePreferences; // @synthesize _cachedTonePreferences;
@property(nonatomic, setter=_setShouldUseServiceToAccessTonePreferences:) _Bool _shouldUseServiceToAccessTonePreferences; // @synthesize _shouldUseServiceToAccessTonePreferences;
@property(retain, nonatomic, setter=_setPreviewBehaviorsByDefaultIdentifier:) NSDictionary *_previewBehaviorsByDefaultIdentifier; // @synthesize _previewBehaviorsByDefaultIdentifier;
@property(retain, nonatomic, setter=_setToneIdentifierAliasMap:) NSDictionary *_toneIdentifierAliasMap; // @synthesize _toneIdentifierAliasMap;
@property(retain, nonatomic, setter=_setAlertTonesByIdentifier:) NSMutableDictionary *_alertTonesByIdentifier; // @synthesize _alertTonesByIdentifier;
@property(retain, nonatomic, setter=_setITunesToneIdentifiersByPID:) NSMutableDictionary *_iTunesToneIdentifiersByPID; // @synthesize _iTunesToneIdentifiersByPID;
@property(retain, nonatomic, setter=_setITunesTonesByIdentifier:) NSMutableDictionary *_iTunesTonesByIdentifier; // @synthesize _iTunesTonesByIdentifier;
- (void)_handleDeviceRingtonesChangedNotification;
- (void)_handleTonePreferencesChangedNotification;
- (_Bool)_toneIsSettableForAlertType:(int)arg1;
- (_Bool)_ensureDirectoryExistsAtPath:(id)arg1;
- (id)_localizedNameOfToneWithIdentifier:(id)arg1;
- (_Bool)_filePathHasSupportedExtensionForRingtone:(id)arg1;
- (id)_fileNameFromToneIdentifier:(id)arg1 withPrefix:(id)arg2;
- (void)_performBlockInAccessQueue:(CDUnknownBlockType)arg1;
- (void)_removeAllSyncedData;
- (_Bool)_removeSyncedToneByPID:(id)arg1;
- (_Bool)_insertSyncedToneMetadata:(id)arg1 fileName:(id)arg2;
- (id)_iTunesToneForPID:(id)arg1;
- (id)_allSyncedTones;
- (_Bool)_transferPurchasedToITunes:(id)arg1;
- (_Bool)_insertPurchasedToneMetadata:(id)arg1 fileName:(id)arg2;
- (void)removeImportedToneWithIdentifier:(id)arg1;
- (void)importTone:(id)arg1 metadata:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (id)newAVItemForToneIdentifier:(id)arg1;
- (_Bool)toneWithIdentifierIsValid:(id)arg1;
- (_Bool)_toneWithIdentifierIsValid:(id)arg1;
- (id)_toneIdentifierForFileAtPath:(id)arg1 isValid:(_Bool *)arg2;
- (id)_toneIdentifierForFileAtPath:(id)arg1;
- (id)_nameForToneIdentifier:(id)arg1 isValid:(_Bool *)arg2;
- (id)nameForToneIdentifier:(id)arg1;
- (id)_previewSoundForToneIdentifier:(id)arg1;
- (id)_filePathForToneIdentifier:(id)arg1 isValid:(_Bool *)arg2;
- (id)filePathForToneIdentifier:(id)arg1;
- (unsigned int)soundIDForToneIdentifier:(id)arg1;
- (id)_defaultRingtonePath;
- (id)_defaultRingtoneName;
- (id)defaultRingtoneIdentifier;
- (id)defaultToneIdentifierForAlertType:(int)arg1;
- (unsigned int)currentToneSoundIDForAlertType:(int)arg1 accountIdentifier:(id)arg2;
- (unsigned int)currentToneSoundIDForAlertType:(int)arg1;
- (id)currentToneNameForAlertType:(int)arg1;
- (void)setCurrentToneIdentifier:(id)arg1 forAlertType:(int)arg2 accountIdentifier:(id)arg3;
- (id)currentToneIdentifierForAlertType:(int)arg1 accountIdentifier:(id)arg2;
- (id)_currentToneIdentifierForAlertType:(int)arg1 accountIdentifier:(id)arg2;
- (void)setCurrentToneIdentifier:(id)arg1 forAlertType:(int)arg2;
- (id)currentToneIdentifierForAlertType:(int)arg1;
- (_Bool)_setToneIdentifierUsingService:(id)arg1 forPreferenceKey:(id)arg2;
- (id)_tonePreferencesFromService;
- (id)_newServiceConnection;
- (_Bool)_toneWithIdentifierIsSystemAlertTone:(id)arg1;
- (_Bool)_toneWithIdentifierIsITunesRingtone:(id)arg1;
- (_Bool)_toneWithIdentifierIsNonDefaultSystemRingtone:(id)arg1;
- (_Bool)_toneWithIdentifierIsDefaultRingtone:(id)arg1;
- (unsigned int)_previewBehaviorForDefaultIdentifier:(id)arg1;
- (void)_loadPreviewBehaviorsByDefaultIdentifier;
- (id)_aliasForToneIdentifier:(id)arg1;
- (void)_loadToneIdentifierAliasMap;
- (void)_loadAlertToneInfo;
- (id)_systemModernSoundDirectory;
- (id)_systemNewSoundDirectory;
- (id)_systemSoundDirectory;
- (id)_baseDirectoryForAlertToneSoundFiles;
- (int)_lockManifestAtPath:(id)arg1;
- (_Bool)_removeToneFromManifestAtPath:(id)arg1 fileName:(id)arg2 deletedMetadata:(id *)arg3;
- (_Bool)_addToneToManifestAtPath:(id)arg1 metadata:(id)arg2 fileName:(id)arg3 mediaDirectory:(id)arg4;
- (unsigned long long)_installedTonesSize;
- (id)_installedTones;
- (id)_iTunesToneWithIdentifier:(id)arg1;
- (void)_reloadITunesRingtonesAfterExternalChange;
- (id)_copyITunesRingtonesFromManifestPath:(id)arg1 mediaDirectoryPath:(id)arg2;
- (void)_loadITunesRingtoneInfoPlistAtPath:(id)arg1;
@property(readonly, nonatomic) NSString *_systemRingtoneDirectory;
@property(readonly, nonatomic) NSString *_iTunesRingtoneInformationPlist;
@property(readonly, nonatomic) NSString *_iTunesRingtoneDirectory;
@property(readonly, nonatomic) NSString *_deviceITunesRingtoneInformationPlist;
@property(readonly, nonatomic) NSString *_deviceITunesRingtoneDirectory;
@property(readonly, nonatomic) NSString *_rootDirectory;
- (void)dealloc;
- (id)initWithITunesRingtonePlistAtPath:(id)arg1;
- (id)init;

@end

@interface TLVibrationManager : NSObject
{
    _Bool _needsRefresh;
    _Bool _allowsAutoRefresh;
    unsigned long long _specialBehaviors;
    NSDictionary *_cachedSystemVibrationPatterns;
    NSDictionary *_cachedUserGeneratedVibrationPatterns;
    TLAccessQueue *_accessQueue;
}

+ (void)_handleVibrateOnRingOrSilentDidChangeNotification;
+ (void)_handleVibrationPreferencesDidChangeNotification;
+ (id)sharedVibrationManager;
@property(retain, setter=_setAccessQueue:) TLAccessQueue *_accessQueue; // @synthesize _accessQueue;
@property(retain, nonatomic, setter=_setCachedUserGeneratedVibrationPatterns:) NSDictionary *_cachedUserGeneratedVibrationPatterns; // @synthesize _cachedUserGeneratedVibrationPatterns;
@property(retain, nonatomic, setter=_setCachedSystemVibrationPatterns:) NSDictionary *_cachedSystemVibrationPatterns; // @synthesize _cachedSystemVibrationPatterns;
@property(nonatomic, setter=_setSpecialBehaviors:) unsigned long long _specialBehaviors; // @synthesize _specialBehaviors;
@property(nonatomic, setter=_setAllowsAutoRefresh:) _Bool _allowsAutoRefresh; // @synthesize _allowsAutoRefresh;
- (void)_setNeedsRefresh:(_Bool)arg1;
@property(nonatomic) _Bool needsRefresh; // @synthesize needsRefresh=_needsRefresh;
- (void)_performBlockInAccessQueue:(CDUnknownBlockType)arg1;
- (void)_makeSystemVibrationDataMigrationVersionCurrentIfNecessary;
- (unsigned long long)_storedSystemVibrationDataMigrationVersion;
- (_Bool)_migrateLegacySettings;
@property(readonly, nonatomic) _Bool shouldVibrateOnSilent;
@property(readonly, nonatomic) _Bool shouldVibrateOnRing;
@property(readonly, nonatomic) _Bool shouldVibrateForCurrentRingerSwitchState;
- (_Bool)_booleanPreferenceForKey:(struct __CFString *)arg1 defaultValue:(_Bool)arg2;
- (_Bool)_removeAllUserGeneratedVibrationPatternsUsingServiceWithError:(id *)arg1;
- (_Bool)_setUserGeneratedVibrationPatternsUsingService:(id)arg1 error:(id *)arg2;
- (id)_retrieveUserGeneratedVibrationPatternsUsingService;
- (id)_newServiceConnection;
- (_Bool)_removeAllUserGeneratedVibrationsWithError:(id *)arg1;
- (unsigned long long)_numberOfUserGeneratedVibrations;
- (_Bool)deleteUserGeneratedVibrationPatternWithIdentifier:(id)arg1 error:(id *)arg2;
- (_Bool)setName:(id)arg1 forUserGeneratedVibrationWithIdentifier:(id)arg2 error:(id *)arg3;
- (id)addUserGeneratedVibrationPattern:(id)arg1 name:(id)arg2 error:(id *)arg3;
- (_Bool)_saveUserGeneratedVibrationPatterns:(id)arg1 error:(id *)arg2;
- (void)_didChangeUserGeneratedVibrationPatterns;
@property(readonly, nonatomic) NSDictionary *_userGeneratedVibrationPatterns;
- (void)_handleUserGeneratedVibrationsDidChangeNotification;
- (_Bool)_vibrationIsSettableForAlertType:(int)arg1;
- (id)_copySystemWideVibrationPatternPreferenceKeyForAlertType:(int)arg1 accountIdentifier:(id)arg2;
- (_Bool)vibrationWithIdentifierIsValid:(id)arg1;
- (id)allUserGeneratedVibrationIdentifiers;
- (id)allUserSelectableSystemVibrationIdentifiers;
- (id)patternForVibrationWithIdentifier:(id)arg1 repeating:(_Bool)arg2;
- (id)patternForVibrationWithIdentifier:(id)arg1;
- (id)nameOfVibrationWithIdentifier:(id)arg1;
- (id)_nameOfVibrationWithIdentifier:(id)arg1;
- (id)_localizedNameForVibrationWithIdentifier:(id)arg1;
- (id)_patternForSystemVibrationWithIdentifier:(id)arg1;
@property(readonly, nonatomic) NSDictionary *_systemVibrationPatterns;
@property(readonly, nonatomic, getter=_isUnitTestingModeEnabled) _Bool _unitTestingModeEnabled;
- (id)noneVibrationPattern;
- (id)noneVibrationName;
- (id)defaultVibrationPatternForAlertType:(int)arg1;
- (id)defaultVibrationNameForAlertType:(int)arg1;
- (id)defaultVibrationIdentifierForAlertType:(int)arg1;
- (id)currentVibrationPatternForAlertType:(int)arg1;
- (id)currentVibrationNameForAlertType:(int)arg1;
- (void)setCurrentVibrationIdentifier:(id)arg1 forAlertType:(int)arg2 accountIdentifier:(id)arg3;
- (id)currentVibrationIdentifierForAlertType:(int)arg1 accountIdentifier:(id)arg2;
- (id)_currentVibrationIdentifierForAlertType:(int)arg1 accountIdentifier:(id)arg2;
- (void)setCurrentVibrationIdentifier:(id)arg1 forAlertType:(int)arg2;
- (id)currentVibrationIdentifierForAlertType:(int)arg1;
- (_Bool)refresh;
@property(nonatomic) _Bool allowsAutoRefresh;
- (void)dealloc;
- (id)_initWithSpecialBehaviors:(unsigned long long)arg1;
- (id)init;

@end

@interface TLVibrationPattern : NSObject
{
    id _contextObject;
    double _duration;
    id _propertyListRepresentation;
    id _complexPatternDescription;
}

+ (id)noneVibrationPattern;
+ (id)complexVibrationPatternWithDurationsForVibrationsAndPauses:(double)arg1;
+ (id)simpleVibrationPatternWithVibrationDuration:(double)arg1 pauseDuration:(double)arg2;
+ (_Bool)isValidVibrationPatternPropertyListRepresentation:(id)arg1;
@property(retain, nonatomic, setter=_setComplexPatternDescription:) id _complexPatternDescription; // @synthesize _complexPatternDescription;
@property(retain, nonatomic, setter=_setPropertyListRepresentation:) id _propertyListRepresentation; // @synthesize _propertyListRepresentation;
@property(nonatomic, setter=_setDuration:) double _duration; // @synthesize _duration;
@property(retain, nonatomic) id contextObject; // @synthesize contextObject=_contextObject;
- (void)appendVibrationComponentWithDuration:(double)arg1 isPause:(_Bool)arg2;
@property(readonly, nonatomic) double computedDuration;
@property(readonly, nonatomic) id _artificiallyRepeatingPropertyListRepresentation;
@property(readonly, nonatomic) id propertyListRepresentation;
- (void)dealloc;
- (id)_initWithPropertyListRepresentation:(id)arg1 skipValidation:(_Bool)arg2;
- (id)initWithPropertyListRepresentation:(id)arg1;
- (id)init;

@end

@interface TLVibrationPersistenceUtilities : NSObject
{
}

+ (id)userGeneratedVibrationStoreFileURL;
+ (_Bool)objectIsValidUserGeneratedVibrationPatternsDictionary:(id)arg1 error:(id *)arg2;
+ (_Bool)_objectIsValidUserGeneratedVibrationPattern:(id)arg1 error:(id *)arg2;
+ (_Bool)_validateObjectWithError:(id *)arg1 validationBlock:(CDUnknownBlockType)arg2;

@end

