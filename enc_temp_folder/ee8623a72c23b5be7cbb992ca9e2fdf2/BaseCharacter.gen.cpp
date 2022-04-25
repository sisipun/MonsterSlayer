// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MonsterSlayer/BaseCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseCharacter() {}
// Cross Module References
	MONSTERSLAYER_API UClass* Z_Construct_UClass_ABaseCharacter_NoRegister();
	MONSTERSLAYER_API UClass* Z_Construct_UClass_ABaseCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_MonsterSlayer();
	MONSTERSLAYER_API UFunction* Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	MONSTERSLAYER_API UFunction* Z_Construct_UFunction_ABaseCharacter_BeginPunch();
	MONSTERSLAYER_API UFunction* Z_Construct_UFunction_ABaseCharacter_ChangeWeapon();
	MONSTERSLAYER_API UFunction* Z_Construct_UFunction_ABaseCharacter_GetAttackPower();
	MONSTERSLAYER_API UFunction* Z_Construct_UFunction_ABaseCharacter_GetHealth();
	MONSTERSLAYER_API UFunction* Z_Construct_UFunction_ABaseCharacter_GetMana();
	MONSTERSLAYER_API UFunction* Z_Construct_UFunction_ABaseCharacter_GetMaxHealth();
	MONSTERSLAYER_API UFunction* Z_Construct_UFunction_ABaseCharacter_GetMaxMana();
	MONSTERSLAYER_API UFunction* Z_Construct_UFunction_ABaseCharacter_IsDead();
	MONSTERSLAYER_API UFunction* Z_Construct_UFunction_ABaseCharacter_IsMovementBlock();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffect_NoRegister();
	MONSTERSLAYER_API UClass* Z_Construct_UClass_UCharacterGameplayAbility_NoRegister();
	MONSTERSLAYER_API UClass* Z_Construct_UClass_UCharacterAttributeSet_NoRegister();
	MONSTERSLAYER_API UClass* Z_Construct_UClass_UCharacterAbilitySystemComponent_NoRegister();
	MONSTERSLAYER_API UClass* Z_Construct_UClass_AWeapon_NoRegister();
	GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
// End Cross Module References
	static FName NAME_ABaseCharacter_BeginPunch = FName(TEXT("BeginPunch"));
	void ABaseCharacter::BeginPunch()
	{
		ProcessEvent(FindFunctionChecked(NAME_ABaseCharacter_BeginPunch),NULL);
	}
	void ABaseCharacter::StaticRegisterNativesABaseCharacter()
	{
		UClass* Class = ABaseCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ActivateAbilitiesWithTags", &ABaseCharacter::execActivateAbilitiesWithTags },
			{ "ChangeWeapon", &ABaseCharacter::execChangeWeapon },
			{ "GetAttackPower", &ABaseCharacter::execGetAttackPower },
			{ "GetHealth", &ABaseCharacter::execGetHealth },
			{ "GetMana", &ABaseCharacter::execGetMana },
			{ "GetMaxHealth", &ABaseCharacter::execGetMaxHealth },
			{ "GetMaxMana", &ABaseCharacter::execGetMaxMana },
			{ "IsDead", &ABaseCharacter::execIsDead },
			{ "IsMovementBlock", &ABaseCharacter::execIsMovementBlock },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics
	{
		struct BaseCharacter_eventActivateAbilitiesWithTags_Parms
		{
			FGameplayTagContainer AbilityTags;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AbilityTags;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((BaseCharacter_eventActivateAbilitiesWithTags_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(BaseCharacter_eventActivateAbilitiesWithTags_Parms), &Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::NewProp_AbilityTags = { "AbilityTags", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BaseCharacter_eventActivateAbilitiesWithTags_Parms, AbilityTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::NewProp_AbilityTags,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "Abilitiy" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCharacter, nullptr, "ActivateAbilitiesWithTags", nullptr, nullptr, sizeof(BaseCharacter_eventActivateAbilitiesWithTags_Parms), Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABaseCharacter_BeginPunch_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseCharacter_BeginPunch_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseCharacter_BeginPunch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCharacter, nullptr, "BeginPunch", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseCharacter_BeginPunch_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_BeginPunch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseCharacter_BeginPunch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseCharacter_BeginPunch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics
	{
		struct BaseCharacter_eventChangeWeapon_Parms
		{
			int32 index;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics::NewProp_index = { "index", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BaseCharacter_eventChangeWeapon_Parms, index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics::NewProp_index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCharacter, nullptr, "ChangeWeapon", nullptr, nullptr, sizeof(BaseCharacter_eventChangeWeapon_Parms), Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseCharacter_ChangeWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseCharacter_ChangeWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics
	{
		struct BaseCharacter_eventGetAttackPower_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BaseCharacter_eventGetAttackPower_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCharacter, nullptr, "GetAttackPower", nullptr, nullptr, sizeof(BaseCharacter_eventGetAttackPower_Parms), Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseCharacter_GetAttackPower()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseCharacter_GetAttackPower_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics
	{
		struct BaseCharacter_eventGetHealth_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BaseCharacter_eventGetHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCharacter, nullptr, "GetHealth", nullptr, nullptr, sizeof(BaseCharacter_eventGetHealth_Parms), Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseCharacter_GetHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseCharacter_GetHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABaseCharacter_GetMana_Statics
	{
		struct BaseCharacter_eventGetMana_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABaseCharacter_GetMana_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BaseCharacter_eventGetMana_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseCharacter_GetMana_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseCharacter_GetMana_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseCharacter_GetMana_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseCharacter_GetMana_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCharacter, nullptr, "GetMana", nullptr, nullptr, sizeof(BaseCharacter_eventGetMana_Parms), Z_Construct_UFunction_ABaseCharacter_GetMana_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_GetMana_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseCharacter_GetMana_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_GetMana_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseCharacter_GetMana()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseCharacter_GetMana_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics
	{
		struct BaseCharacter_eventGetMaxHealth_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BaseCharacter_eventGetMaxHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCharacter, nullptr, "GetMaxHealth", nullptr, nullptr, sizeof(BaseCharacter_eventGetMaxHealth_Parms), Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseCharacter_GetMaxHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseCharacter_GetMaxHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics
	{
		struct BaseCharacter_eventGetMaxMana_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BaseCharacter_eventGetMaxMana_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCharacter, nullptr, "GetMaxMana", nullptr, nullptr, sizeof(BaseCharacter_eventGetMaxMana_Parms), Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseCharacter_GetMaxMana()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseCharacter_GetMaxMana_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABaseCharacter_IsDead_Statics
	{
		struct BaseCharacter_eventIsDead_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((BaseCharacter_eventIsDead_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(BaseCharacter_eventIsDead_Parms), &Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCharacter, nullptr, "IsDead", nullptr, nullptr, sizeof(BaseCharacter_eventIsDead_Parms), Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseCharacter_IsDead()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseCharacter_IsDead_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics
	{
		struct BaseCharacter_eventIsMovementBlock_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((BaseCharacter_eventIsMovementBlock_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(BaseCharacter_eventIsMovementBlock_Parms), &Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCharacter, nullptr, "IsMovementBlock", nullptr, nullptr, sizeof(BaseCharacter_eventIsMovementBlock_Parms), Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseCharacter_IsMovementBlock()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseCharacter_IsMovementBlock_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABaseCharacter_NoRegister()
	{
		return ABaseCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ABaseCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAttackComboActivated_MetaData[];
#endif
		static void NewProp_bAttackComboActivated_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAttackComboActivated;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementBlockTags_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_MovementBlockTags;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MovementBlockTags_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PassiveEffects_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PassiveEffects;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_PassiveEffects_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Abilities_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Abilities;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Abilities_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Attributes_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Attributes;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Weapons_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Weapons;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Weapons_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CurrentWeapon;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABaseCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MonsterSlayer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABaseCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABaseCharacter_ActivateAbilitiesWithTags, "ActivateAbilitiesWithTags" }, // 1559251695
		{ &Z_Construct_UFunction_ABaseCharacter_BeginPunch, "BeginPunch" }, // 597379087
		{ &Z_Construct_UFunction_ABaseCharacter_ChangeWeapon, "ChangeWeapon" }, // 1728014908
		{ &Z_Construct_UFunction_ABaseCharacter_GetAttackPower, "GetAttackPower" }, // 4268161160
		{ &Z_Construct_UFunction_ABaseCharacter_GetHealth, "GetHealth" }, // 2229184735
		{ &Z_Construct_UFunction_ABaseCharacter_GetMana, "GetMana" }, // 1814290325
		{ &Z_Construct_UFunction_ABaseCharacter_GetMaxHealth, "GetMaxHealth" }, // 684133826
		{ &Z_Construct_UFunction_ABaseCharacter_GetMaxMana, "GetMaxMana" }, // 2871839730
		{ &Z_Construct_UFunction_ABaseCharacter_IsDead, "IsDead" }, // 3397538920
		{ &Z_Construct_UFunction_ABaseCharacter_IsMovementBlock, "IsMovementBlock" }, // 1567694247
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BaseCharacter.h" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseCharacter_Statics::NewProp_bAttackComboActivated_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	void Z_Construct_UClass_ABaseCharacter_Statics::NewProp_bAttackComboActivated_SetBit(void* Obj)
	{
		((ABaseCharacter*)Obj)->bAttackComboActivated = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_bAttackComboActivated = { "bAttackComboActivated", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ABaseCharacter), &Z_Construct_UClass_ABaseCharacter_Statics::NewProp_bAttackComboActivated_SetBit, METADATA_PARAMS(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_bAttackComboActivated_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_bAttackComboActivated_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseCharacter_Statics::NewProp_MovementBlockTags_MetaData[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_MovementBlockTags = { "MovementBlockTags", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABaseCharacter, MovementBlockTags), METADATA_PARAMS(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_MovementBlockTags_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_MovementBlockTags_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_MovementBlockTags_Inner = { "MovementBlockTags", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseCharacter_Statics::NewProp_PassiveEffects_MetaData[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_PassiveEffects = { "PassiveEffects", nullptr, (EPropertyFlags)0x0014000000000015, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABaseCharacter, PassiveEffects), METADATA_PARAMS(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_PassiveEffects_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_PassiveEffects_MetaData)) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_PassiveEffects_Inner = { "PassiveEffects", nullptr, (EPropertyFlags)0x0004000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameplayEffect_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Abilities_MetaData[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Abilities = { "Abilities", nullptr, (EPropertyFlags)0x0014000000000015, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABaseCharacter, Abilities), METADATA_PARAMS(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Abilities_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Abilities_MetaData)) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Abilities_Inner = { "Abilities", nullptr, (EPropertyFlags)0x0004000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCharacterGameplayAbility_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Attributes_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Attributes = { "Attributes", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABaseCharacter, Attributes), Z_Construct_UClass_UCharacterAttributeSet_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Attributes_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Attributes_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseCharacter_Statics::NewProp_AbilitySystemComponent_MetaData[] = {
		{ "Category", "Ability" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_AbilitySystemComponent = { "AbilitySystemComponent", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABaseCharacter, AbilitySystemComponent), Z_Construct_UClass_UCharacterAbilitySystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_AbilitySystemComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_AbilitySystemComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Weapons_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Weapons = { "Weapons", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABaseCharacter, Weapons), METADATA_PARAMS(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Weapons_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Weapons_MetaData)) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Weapons_Inner = { "Weapons", nullptr, (EPropertyFlags)0x0004000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AWeapon_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseCharacter_Statics::NewProp_CurrentWeapon_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseCharacter_Statics::NewProp_CurrentWeapon = { "CurrentWeapon", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABaseCharacter, CurrentWeapon), Z_Construct_UClass_AWeapon_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_CurrentWeapon_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::NewProp_CurrentWeapon_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABaseCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_bAttackComboActivated,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_MovementBlockTags,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_MovementBlockTags_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_PassiveEffects,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_PassiveEffects_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Abilities,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Abilities_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Attributes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_AbilitySystemComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Weapons,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_Weapons_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseCharacter_Statics::NewProp_CurrentWeapon,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ABaseCharacter_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(ABaseCharacter, IAbilitySystemInterface), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABaseCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABaseCharacter_Statics::ClassParams = {
		&ABaseCharacter::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABaseCharacter_Statics::PropPointers,
		InterfaceParams,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::PropPointers),
		ARRAY_COUNT(InterfaceParams),
		0x009000A1u,
		METADATA_PARAMS(Z_Construct_UClass_ABaseCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABaseCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABaseCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABaseCharacter, 1776548956);
	template<> MONSTERSLAYER_API UClass* StaticClass<ABaseCharacter>()
	{
		return ABaseCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABaseCharacter(Z_Construct_UClass_ABaseCharacter, &ABaseCharacter::StaticClass, TEXT("/Script/MonsterSlayer"), TEXT("ABaseCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
