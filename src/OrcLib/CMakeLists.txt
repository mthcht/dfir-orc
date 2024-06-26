#
# SPDX-License-Identifier: LGPL-2.1-or-later
#
# Copyright © 2011-2019 ANSSI. All Rights Reserved.
#
# Author(s): fabienfl
#            Jean Gautier
#

include(${ORC_ROOT}/cmake/Orc.cmake)
orc_add_compile_options()

find_package(7zip CONFIG REQUIRED)
find_package(Boost REQUIRED)
find_package(fmt REQUIRED)
find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(VisualStudio REQUIRED)
find_package(Yara REQUIRED)

set(SRC_COMMAND
    "CommandAgent.cpp"
    "CommandAgent.h"
    "CommandAgentResources.cpp"
    "CommandAgentResources.h"
    "CommandExecute.cpp"
    "CommandExecute.h"
    "CommandMessage.cpp"
    "CommandMessage.h"
    "CommandNotification.cpp"
    "CommandNotification.h"
    "DbgHelpLibrary.cpp"
    "DbgHelpLibrary.h"
    "DebugAgent.cpp"
    "DebugAgent.h"
    "ProcessRedirect.cpp"
    "ProcessRedirect.h"
)

source_group(Command FILES ${SRC_COMMAND})

set(SRC_COMMON
    "OrcLib.h"
    "OrcLimits.h"
    "Limit.h"
    "targetver.h"
    "CpuId.h"
    "CpuId.cpp"
    "CpuInfo.h"
    "CpuInfo.cpp"
)

# stdafx.[cpp|h] must be included first, don't include them in SRC_COMMON
source_group(Common FILES "stdafx.h" ${SRC_COMMON})

set(SRC_CONFIG
    "Configuration/ConfigFile.cpp"
    "Configuration/ConfigFile.h"
    "Configuration/ConfigFile_Common.cpp"
    "Configuration/ConfigFile_Common.h"
    "Configuration/ConfigFileReader.cpp"
    "Configuration/ConfigFileReader.h"
    "Configuration/ConfigFileWriter.cpp"
    "Configuration/ConfigFileWriter.h"
    "Configuration/ConfigItem.cpp"
    "Configuration/ConfigItem.h"
    "Configuration/Option.cpp"
    "Configuration/Option.h"
)

source_group(Config FILES ${SRC_CONFIG})

set(SRC_DISK
    "DiskStructures.h"
    "Partition.cpp"
    "Partition.h"
    "PartitionType.cpp"
    "PartitionType.h"
    "PartitionFlags.cpp"
    "PartitionFlags.h"
    "PartitionTable.cpp"
    "PartitionTable.h"
)

source_group(Disk FILES ${SRC_DISK})

set(SRC_DISK_FILESYSTEM
    "DataDetails.h"
    "FileInfo.cpp"
    "FileInfo.h"
    "FSUtils.h"
    "FSVBR.h"
    "FSVBR_FSType.h"
    "GenDataStructure.h"
    "BitLocker.h"
    "PEInfo.cpp"
    "PEInfo.h"
)

source_group(Disk\\FileSystem FILES ${SRC_DISK_FILESYSTEM})

set(SRC_DISK_FILESYSTEM_FAT
    "FileSystem.h"
    "FatDataStructures.h"
    "FatFileEntry.cpp"
    "FatFileEntry.h"
    "FatFileInfo.cpp"
    "FatFileInfo.h"
    "FatFileInfo_ColumnDef.cpp"
    "FatTable.h"
    "FatTableEntry.h"
    "FatWalker.cpp"
    "FatWalker.h"
    "SegmentDetails.h"
)

source_group(Disk\\FileSystem\\FAT FILES ${SRC_DISK_FILESYSTEM_FAT})

set(SRC_DISK_FILESYSTEM_NTFS
    "FileFind.cpp"
    "FileFind.h"
    "NTFSCompression.cpp"
    "NTFSCompression.h"
    "NtfsDataStructures.h"
)

source_group(Disk\\FileSystem\\NTFS FILES ${SRC_DISK_FILESYSTEM_NTFS})

set(SRC_DISK_FILESYSTEM_NTFS_FILEINFO
    "MFTRecordFileInfo.cpp"
    "MFTRecordFileInfo.h"
    "NtfsFileInfo.cpp"
    "NtfsFileInfo.h"
    "NtfsFileInfo_ColumnDef.cpp"
    "USNRecordFileInfo.cpp"
    "USNRecordFileInfo.h"
)

source_group(Disk\\FileSystem\\NTFS\\FileInfo
    FILES ${SRC_DISK_FILESYSTEM_NTFS_FILEINFO}
)

set(SRC_DISK_FILESYSTEM_NTFS_MFT
    "IMFT.h"
    "MFTOffline.cpp"
    "MFTOffline.h"
    "MFTOnline.cpp"
    "MFTOnline.h"
    "MFTUtils.cpp"
    "MFTUtils.h"
    "MFTWalker.cpp"
    "MFTWalker.h"
    "ResurrectRecordsMode.h"
    "ResurrectRecordsMode.cpp"
)

source_group(Disk\\FileSystem\\NTFS\\MFT FILES ${SRC_DISK_FILESYSTEM_NTFS_MFT})

set(SRC_DISK_FILESYSTEM_NTFS_MFT_RECORD
    "AttributeList.cpp"
    "AttributeList.h"
    "MFTRecord.cpp"
    "MFTRecord.h"
    "MftRecordAttribute.cpp"
    "MftRecordAttribute.h"
)

source_group(Disk\\FileSystem\\NTFS\\MFT\\Record
    FILES ${SRC_DISK_FILESYSTEM_NTFS_MFT_RECORD}
)

set(SRC_DISK_FILESYSTEM_NTFS_MFT_USN
    "IUSNJournalWalker.h"
    "USNJournalWalker.cpp"
    "USNJournalWalker.h"
    "USNJournalWalkerBase.cpp"
    "USNJournalWalkerBase.h"
    "USNJournalWalkerOffline.cpp"
    "USNJournalWalkerOffline.h"
    )

source_group(Disk\\FileSystem\\NTFS\\MFT\\USN
    FILES ${SRC_DISK_FILESYSTEM_NTFS_MFT_USN}
)

set(SRC_DISK_FILESYSTEM_REFS RefsDataStructures.h)

source_group(Disk\\FileSystem\\ReFS FILES ${SRC_DISK_FILESYSTEM_REFS})

set(SRC_DISK_LOCATION
    "Location.cpp"
    "Location.h"
    "LocationType.h"
    "LocationType.cpp"
    "LocationSet.cpp"
    "LocationSet.h"
)

source_group(Disk\\Location FILES ${SRC_DISK_LOCATION})

set(SRC_DISK_VOLUME
    "CompleteVolumeReader.cpp"
    "CompleteVolumeReader.h"
    "DiskExtent.cpp"
    "DiskExtent.h"
    "EnumDisk.cpp"
    "EnumDisk.h"
    "IDiskExtent.h"
    "ImageReader.cpp"
    "ImageReader.h"
    "InterfaceReader.cpp"
    "InterfaceReader.h"
    "MountedVolumeReader.cpp"
    "MountedVolumeReader.h"
    "OfflineMFTReader.cpp"
    "OfflineMFTReader.h"
    "PhysicalDiskReader.cpp"
    "PhysicalDiskReader.h"
    "ShadowCopyVolumeReader.cpp"
    "ShadowCopyVolumeReader.h"
    "SnapshotVolumeReader.cpp"
    "SnapshotVolumeReader.h"
    "SystemStorageReader.cpp"
    "SystemStorageReader.h"
    "VHDVolumeReader.cpp"
    "VHDVolumeReader.h"
    "VolumeReader.cpp"
    "VolumeReader.h"
    "VolumeReaderVisitor.h"
    "VolumeShadowCopies.cpp"
    "VolumeShadowCopies.h"
    "VssAPIExtension.cpp"
    "VssAPIExtension.h"
)

source_group(Disk\\Volume FILES ${SRC_DISK_VOLUME})

set(SRC_EXTENSIONLIBRARIES
    "XmlLiteExtension.cpp"
    "XmlLiteExtension.h"
    "COMExtension.cpp"
    "COMExtension.h"
    "CompressAPIExtension.cpp"
    "CompressAPIExtension.h"
    "EvtLibrary.cpp"
    "EvtLibrary.h"
    "ExtensionLibrary.cpp"
    "ExtensionLibrary.h"
    "Kernel32Extension.cpp"
    "Kernel32Extension.h"
    "NtDllExtension.cpp"
    "NtDllExtension.h"
)

source_group(ExtensionLibraries FILES ${SRC_EXTENSIONLIBRARIES})

set(SRC_EXTENSIONLIBRARIES_YARA
    "YaraStaticExtension.cpp"
    "YaraStaticExtension.h"
    "YaraScanner.cpp"
    "YaraScanner.h"
)

source_group(ExtensionLibraries\\Yara FILES ${SRC_EXTENSIONLIBRARIES_YARA})

set(SRC_FILE_FORMAT
    "FileFormat/PeParser.h"
    "FileFormat/PeParser.cpp"
)

source_group(FileFormat
    FILES ${SRC_FILE_FORMAT}
)

set(SRC_INOUT
    "LocationOutput.h"
    "OutputWriter.h"
    "FileDisposition.h"
    "FileDisposition.cpp"
)

source_group(In&Out FILES ${SRC_INOUT})

set(SRC_INOUT_ARCHIVE
    "Archive.cpp"
    "Archive.h"
    "ArchiveAgent.cpp"
    "ArchiveAgent.h"
    "ArchiveCreate.cpp"
    "ArchiveCreate.h"
    "ArchiveExtract.cpp"
    "ArchiveExtract.h"
    "ArchiveFormat.h"
    "ArchiveFormat.cpp"
    "ArchiveMessage.cpp"
    "ArchiveMessage.h"
    "ArchiveNotification.cpp"
    "ArchiveNotification.h"
)

source_group(In&Out\\Archive FILES ${SRC_INOUT_ARCHIVE})

set(SRC_INOUT_ARCHIVER
    "Archive/Appender.h"
    "Archive/CompressionLevel.h"
    "Archive/CompressionLevel.cpp"
    "Archive/IArchive.h"
    "Archive/Item.cpp"
    "Archive/Item.h"
    "Archive/7z/Archive7z.cpp"
    "Archive/7z/Archive7z.h"
    "Archive/7z/ArchiveOpenCallback.h"
    "Archive/7z/ArchiveOpenCallback.cpp"
    "Archive/7z/ArchiveUpdateCallback.cpp"
    "Archive/7z/ArchiveUpdateCallback.h"
    "Archive/7z/InStreamAdapter.cpp"
    "Archive/7z/InStreamAdapter.h"
    "Archive/7z/OutStreamAdapter.cpp"
    "Archive/7z/OutStreamAdapter.h"
)

source_group(In&Out\\Archiver FILES ${SRC_INOUT_ARCHIVER})

set(SRC_INOUT_ARCHIVE_SEVENZIP
    "ArchiveExtractCallback.cpp"
    "ArchiveExtractCallback.h"
    "ArchiveOpenCallback.cpp"
    "ArchiveOpenCallback.h"
    "ArchiveUpdateCallback.cpp"
    "ArchiveUpdateCallback.h"
    "GUIDs.cpp"
    "PropVariant.cpp"
    "PropVariant.h"
    "ZipCreate.cpp"
    "ZipCreate.h"
    "ZipExtract.cpp"
    "ZipExtract.h"
    "ZipLibrary.cpp"
    "ZipLibrary.h"
)

source_group(In&Out\\Archive\\SevenZip FILES ${SRC_INOUT_ARCHIVE_SEVENZIP})

set(SRC_INOUT_BYTESTREAM
    "ByteStream.cpp"
    "ByteStream.h"
    "ByteStreamHelpers.h"
)

source_group(In&Out\\ByteStream FILES ${SRC_INOUT_BYTESTREAM})

set(SRC_INOUT_BYTESTREAM_CRYPTOSTREAM
    "CryptoHashStream.cpp"
    "CryptoHashStream.h"
    "CryptoHashStreamAlgorithm.h"
    "FuzzyHashStream.cpp"
    "FuzzyHashStream.h"
    "FuzzyHashStreamAlgorithm.h"
    "HashStream.cpp"
    "HashStream.h"
    "PasswordEncryptedStream.cpp"
    "PasswordEncryptedStream.h"
)

source_group(In&Out\\ByteStream\\CryptoStream
    FILES ${SRC_INOUT_BYTESTREAM_CRYPTOSTREAM}
)

set(SRC_INOUT_BYTESTREAM_FSSTREAM_FATSTREAM
    "FatStream.cpp"
    "FatStream.h"
)

source_group(In&Out\\ByteStream\\FSStream\\FatStream
    FILES ${SRC_INOUT_BYTESTREAM_FSSTREAM_FATSTREAM}
)

set(SRC_INOUT_BYTESTREAM_FSSTREAM_NTFSSTREAM
    "NTFSStream.cpp"
    "NTFSStream.h"
    "UncompressNTFSStream.cpp"
    "UncompressNTFSStream.h"
    "UncompressWofStream.cpp"
    "UncompressWofStream.h"
)

source_group(In&Out\\ByteStream\\FSStream\\NTFSStream
    FILES ${SRC_INOUT_BYTESTREAM_FSSTREAM_NTFSSTREAM}
)

set(SRC_INOUT_BYTESTREAM_MESSAGESTREAM
    "EncodeMessageStream.cpp"
    "EncodeMessageStream.h"
    "MessageStream.cpp"
    "MessageStream.h"
)

source_group(In&Out\\ByteStream\\MessageStream
    FILES ${SRC_INOUT_BYTESTREAM_MESSAGESTREAM}
)

set(SRC_INOUT_BYTESTREAM_SYSTEMSTREAM
    "FileMappingStream.cpp"
    "FileMappingStream.h"
    "FileStream.cpp"
    "FileStream.h"
    "PipeStream.cpp"
    "PipeStream.h"
    "ResourceStream.cpp"
    "ResourceStream.h"
    "SparseStream.cpp"
    "SparseStream.h"
    "ByteStreamVisitor.h"
)

source_group(In&Out\\ByteStream\\SystemStream
    FILES ${SRC_INOUT_BYTESTREAM_SYSTEMSTREAM}
)

set(SRC_INOUT_BYTESTREAM_UTILITYSTREAM
    "AccumulatingStream.cpp"
    "AccumulatingStream.h"
    "BufferStream.h"
    "CacheStream.cpp"
    "CacheStream.h"
    "ChainingStream.cpp"
    "ChainingStream.h"
    "DevNullStream.cpp"
    "DevNullStream.h"
    "JournalingStream.cpp"
    "JournalingStream.h"
    "MemoryStream.cpp"
    "MemoryStream.h"
    "MultiMemoryStream.cpp"
    "MultiMemoryStream.h"
    "StringsStream.cpp"
    "StringsStream.h"
    "TeeStream.cpp"
    "TeeStream.h"
    "TemporaryStream.cpp"
    "TemporaryStream.h"
)

source_group(In&Out\\ByteStream\\UtilityStream
    FILES ${SRC_INOUT_BYTESTREAM_UTILITYSTREAM}
)

set(SRC_INOUT_BYTESTREAM_WRAPPERSTREAM
    "DiskChunkStream.cpp"
    "DiskChunkStream.h"
    "InByteStreamWrapper.cpp"
    "InByteStreamWrapper.h"
    "ISequentialStreamWrapper.cpp"
    "ISequentialStreamWrapper.h"
    "IStreamWrapper.cpp"
    "IStreamWrapper.h"
    "OutByteStreamWrapper.cpp"
    "OutByteStreamWrapper.h"
)

source_group(In&Out\\ByteStream\\WrapperStream
    FILES ${SRC_INOUT_BYTESTREAM_WRAPPERSTREAM}
)

set(SRC_INOUT_CONCURRENT
    "BoundedBuffer.h"
    "MessageQueue.h"
    "PriorityBuffer.h"
    "Semaphore.h"
)

source_group(In&Out\\Concurrent FILES ${SRC_INOUT_CONCURRENT})

set(SRC_INOUT_DOWNLOAD
    "BITSDownloadTask.cpp"
    "BITSDownloadTask.h"
    "DownloadTask.cpp"
    "DownloadTask.h"
    "FileCopyDownloadTask.cpp"
    "FileCopyDownloadTask.h"
)

source_group(In&Out\\Download FILES ${SRC_INOUT_DOWNLOAD})

set(SRC_INOUT_LOGPARSER "LogParserDataReader.h")

source_group(In&Out\\LogParser FILES ${SRC_INOUT_LOGPARSER})

set(SRC_INOUT_STRUCTUREDOUTPUT
    "RobustStructuredWriter.cpp"
    "RobustStructuredWriter.h"
    "StructuredOutputWriter.cpp"
    "StructuredOutputWriter.h"
    "StructuredOutput.h"
)

source_group(In&Out\\StructuredOutput FILES ${SRC_INOUT_STRUCTUREDOUTPUT})

set(SRC_INOUT_STRUCTUREDOUTPUT_XML
    "XmlOutputWriter.cpp"
    "XmlOutputWriter.h"
)

source_group(In&Out\\StructuredOutput\\XML
    FILES ${SRC_INOUT_STRUCTUREDOUTPUT_XML}
)

set(SRC_INOUT_STRUCTUREDOUTPUT_JSON
    "JSONOutputWriter.cpp"
    "JSONOutputWriter.h"
)

source_group(In&Out\\StructuredOutput\\JSON
    FILES ${SRC_INOUT_STRUCTUREDOUTPUT_JSON}
)


set(SRC_INOUT_TABLEOUTPUT
    "BoundTableRecord.cpp"
    "BoundTableRecord.h"
    "TableOutput.h"
    "TableOutputExtension.cpp"
    "TableOutputExtension.h"
    "TableOutputWriter.cpp"
    "TableOutputWriter.h"
)

source_group(In&Out\\TableOutput FILES ${SRC_INOUT_TABLEOUTPUT})

set(SRC_INOUT_TABLEOUTPUT_CSV
    "CsvCruncher.cpp"
    "CsvCruncher.h"
    "CsvDataReader.h"
    "CsvFileReader.cpp"
    "CsvFileReader.h"
    "CsvFileWriter.cpp"
    "CsvFileWriter.h"
    "CsvStream.cpp"
    "CsvStream.h"
)

source_group(In&Out\\TableOutput\\CSV FILES ${SRC_INOUT_TABLEOUTPUT_CSV})

set(SRC_INOUT_TABLEOUTPUT_PARQUET ParquetOutputWriter.h)

source_group(In&Out\\TableOutput\\Parquet
    FILES ${SRC_INOUT_TABLEOUTPUT_PARQUET}
)

set(SRC_INOUT_TABLEOUTPUT_APACHE_ORC ApacheOrcOutputWriter.h)

source_group(In&Out\\TableOutput\\ApacheOrc
    FILES ${SRC_INOUT_TABLEOUTPUT_APACHE_ORC}
)

set(SRC_FILESYSTEM
    "Filesystem/FileAttribute.h"
    "Filesystem/FileAttribute.cpp"
    "Filesystem/Ntfs/Attribute/ReparsePoint/WofReparsePoint.h"
    "Filesystem/Ntfs/Attribute/ReparsePoint/WofReparsePoint.cpp"
    "Filesystem/Ntfs/Compression/WofChunks.h"
    "Filesystem/Ntfs/Compression/WofChunks.cpp"
    "Filesystem/Ntfs/Compression/WofStreamConcept.h"
    "Filesystem/Ntfs/Compression/WofAlgorithm.h"
    "Filesystem/Ntfs/Compression/WofAlgorithm.cpp"
    "Filesystem/Ntfs/Compression/DecompressorConcept.h"
    "Filesystem/Ntfs/Compression/Engine/Nt/NtAlgorithm.h"
    "Filesystem/Ntfs/Compression/Engine/Nt/NtAlgorithm.cpp"
    "Filesystem/Ntfs/Compression/Engine/Nt/NtApi.h"
    "Filesystem/Ntfs/Compression/Engine/Nt/NtApi.cpp"
    "Filesystem/Ntfs/Compression/Engine/Nt/NtDecompressorConcept.h"
    "Filesystem/Ntfs/Compression/Engine/Nt/NtDecompressorConcept.cpp"
    "Filesystem/Ntfs/Compression/Engine/Wimlib/WimlibAlgorithm.h"
    "Filesystem/Ntfs/Compression/Engine/Wimlib/WimlibAlgorithm.cpp"
    "Filesystem/Ntfs/Compression/Engine/Wimlib/WimlibApi.h"
    "Filesystem/Ntfs/Compression/Engine/Wimlib/WimlibApi.cpp"
    "Filesystem/Ntfs/Compression/Engine/Wimlib/WimlibErrorCategory.h"
    "Filesystem/Ntfs/Compression/Engine/Wimlib/WimlibErrorCategory.cpp"
    "Filesystem/Ntfs/ShadowCopy/ApplicationInformation.h"
    "Filesystem/Ntfs/ShadowCopy/ApplicationInformation.cpp"
    "Filesystem/Ntfs/ShadowCopy/Catalog.h"
    "Filesystem/Ntfs/ShadowCopy/Catalog.cpp"
    "Filesystem/Ntfs/ShadowCopy/CatalogEntry.h"
    "Filesystem/Ntfs/ShadowCopy/CatalogEntry.cpp"
    "Filesystem/Ntfs/ShadowCopy/CatalogEntryType.h"
    "Filesystem/Ntfs/ShadowCopy/CatalogEntryType.cpp"
    "Filesystem/Ntfs/ShadowCopy/CatalogHeader.h"
    "Filesystem/Ntfs/ShadowCopy/CatalogHeader.cpp"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaBitmap.h"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaBitmap.cpp"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaLocationTable.h"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaLocationTable.cpp"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaLocationTableEntry.h"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaLocationTableEntry.cpp"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaLocationTableHeader.h"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaLocationTableHeader.cpp"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaTable.h"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaTable.cpp"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaTableEntry.h"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaTableEntry.cpp"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaTableEntryFlags.h"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaTableEntryFlags.cpp"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaTableHeader.h"
    "Filesystem/Ntfs/ShadowCopy/DiffAreaTableHeader.cpp"
    "Filesystem/Ntfs/ShadowCopy/Dump.h"
    "Filesystem/Ntfs/ShadowCopy/Dump.cpp"
    "Filesystem/Ntfs/ShadowCopy/Node.h"
    "Filesystem/Ntfs/ShadowCopy/Node.cpp"
    "Filesystem/Ntfs/ShadowCopy/NodeType.h"
    "Filesystem/Ntfs/ShadowCopy/NodeType.cpp"
    "Filesystem/Ntfs/ShadowCopy/ParserType.h"
    "Filesystem/Ntfs/ShadowCopy/ParserType.cpp"
    "Filesystem/Ntfs/ShadowCopy/ShadowCopy.h"
    "Filesystem/Ntfs/ShadowCopy/ShadowCopy.cpp"
    "Filesystem/Ntfs/ShadowCopy/ShadowCopyStream.h"
    "Filesystem/Ntfs/ShadowCopy/ShadowCopyStream.cpp"
    "Filesystem/Ntfs/ShadowCopy/ShadowCopyInformation.h"
    "Filesystem/Ntfs/ShadowCopy/ShadowCopyInformation.cpp"
    "Filesystem/Ntfs/ShadowCopy/Snapshot.h"
    "Filesystem/Ntfs/ShadowCopy/Snapshot.cpp"
    "Filesystem/Ntfs/ShadowCopy/SnapshotContext.h"
    "Filesystem/Ntfs/ShadowCopy/SnapshotContext.cpp"
    "Filesystem/Ntfs/ShadowCopy/SnapshotInformation.h"
    "Filesystem/Ntfs/ShadowCopy/SnapshotsIndex.h"
    "Filesystem/Ntfs/ShadowCopy/SnapshotsIndex.cpp"
    "Filesystem/Ntfs/ShadowCopy/SnapshotsIndexHeader.h"
    "Filesystem/Ntfs/ShadowCopy/SnapshotsIndexHeader.cpp"
    "Filesystem/Ntfs/ShadowCopy/VolumeSnapshotAttributes.h"
    "Filesystem/Ntfs/ShadowCopy/VolumeSnapshotAttributes.cpp"
)

source_group(Filesystem
    FILES ${SRC_FILESYSTEM}
)

set(SRC_STREAM
    "Stream/BasicStreamReader.h"
    "Stream/BufferStreamConcept.h"
    "Stream/ByteStreamConcept.h"
    "Stream/FileStreamConcept.h"
    "Stream/FileStreamConcept.cpp"
    "Stream/SeekDirection.h"
    "Stream/SpanStreamConcept.h"
    "Stream/Stream.h"
    "Stream/StreamConcept.h"
    "Stream/StreamReader.h"
    "Stream/StreamUtils.h"
    "Stream/VolumeStreamReader.h"
    "Stream/VolumeStreamReader.cpp"
)

source_group(Stream
    FILES ${SRC_STREAM}
)

set(SRC_TEXT
    "Text/Encoding.h"
    "Text/Encoding.cpp"
    "Text/Iconv.h"
    "Text/Iconv.cpp"
    "Text/Format.h"
    "Text/Guid.h"
    "Text/Guid.cpp"
    "Text/Hex.h"
    "Text/HexDump.h"
    "Text/in_addr.h"
    "Text/in_addr.cpp"
    "Text/StdoutContainerAdapter.h"
    "Text/Tree.h"
    "Text/Tree.cpp"
)

source_group(Text FILES ${SRC_TEXT})

set(SRC_TEXT_FMT
    "Text/Fmt/Boolean.h"
    "Text/Fmt/BoolOnOff.h"
    "Text/Fmt/ByteQuantity.h"
    "Text/Fmt/CryptoHashStreamAlgorithm.h"
    "Text/Fmt/FILE_NAME.h"
    "Text/Fmt/FILETIME.h"
    "Text/Fmt/FSVBR.h"
    "Text/Fmt/FuzzyHashStreamAlgorithm.h"
    "Text/Fmt/GUID.h"
    "Text/Fmt/Limit.h"
    "Text/Fmt/LocationType.h"
    "Text/Fmt/Offset.h"
    "Text/Fmt/OutputSpecTypes.h"
    "Text/Fmt/Partition.h"
    "Text/Fmt/PartitionFlags.h"
    "Text/Fmt/PartitionType.h"
    "Text/Fmt/Result.h"
    "Text/Fmt/std_error_code.h"
    "Text/Fmt/std_filesystem.h"
    "Text/Fmt/std_optional.h"
    "Text/Fmt/SYSTEMTIME.h"
    "Text/Fmt/TimeUtc.h"
)

source_group(Text\\Fmt FILES ${SRC_TEXT_FMT})

set(SRC_TEXT_PRINT
    "Text/Print.h"
    "Text/Print/EmbedSpec.h"
    "Text/Print/EmbedSpec.cpp"
    "Text/Print/FILE_NAME.h"
    "Text/Print/FILE_NAME.cpp"
    "Text/Print/Filter.h"
    "Text/Print/Filter.cpp"
    "Text/Print/Intentions.h"
    "Text/Print/Intentions.cpp"
    "Text/Print/Location.h"
    "Text/Print/Location.cpp"
    "Text/Print/LocationSet.h"
    "Text/Print/LocationSet.cpp"
    "Text/Print/Ntfs.h"
    "Text/Print/OutputSpec.h"
    "Text/Print/OutputSpec.cpp"
    "Text/Print/Partition.h"
    "Text/Print/Partition.cpp"
    "Text/Print/SearchTerm.h"
    "Text/Print/SearchTerm.cpp"
    "Text/Print/Tribool.h"
    "Text/Print/Tribool.cpp"
    "Text/Print/Ntfs/AttributeListEntry.h"
    "Text/Print/Ntfs/AttributeListEntry.cpp"
    "Text/Print/Ntfs/NonResidentAttributeExtent.h"
    "Text/Print/Ntfs/NonResidentAttributeExtent.cpp"
    "Text/Print/Ntfs/MFTRecord.h"
    "Text/Print/Ntfs/MFTRecord.cpp"
)

source_group(Text\\Print FILES ${SRC_TEXT_PRINT})

set(SRC_INOUT_UPLOAD
    "BITSAgent.cpp"
    "BITSAgent.h"
    "CopyFileAgent.cpp"
    "CopyFileAgent.h"
    "UploadAgent.cpp"
    "UploadAgent.h"
    "UploadMessage.cpp"
    "UploadMessage.h"
    "UploadNotification.cpp"
    "UploadNotification.h"
)

source_group(In&Out\\Upload FILES ${SRC_INOUT_UPLOAD})

set(SRC_LOG
    "Log/FileSink.h"
    "Log/Level.h"
    "Log/Level.cpp"
    "Log/Log.cpp"
    "Log/Log.h"
    "Log/Logger.cpp"
    "Log/Logger.h"
    "Log/LogTerminationHandler.h"
    "Log/MemorySink.h"
    "Log/SpdlogLogger.h"
    "Log/SpdlogLogger.cpp"
    "Log/SpdlogSink.h"
    "Log/Syslog/Syslog.h"
    "Log/Syslog/Syslog.cpp"
    "Log/Syslog/SyslogMessage.h"
    "Log/Syslog/SyslogMessage.cpp"
    "Log/Syslog/SyslogLevel.h"
    "Log/Syslog/SyslogLevel.cpp"
    "Log/Syslog/SyslogFacility.h"
    "Log/Syslog/SyslogSink.h"
    "Log/Syslog/SyslogSink.cpp"
    "Log/Syslog/UdpSocket.h"
    "Log/Syslog/UdpSocket.cpp"
)

source_group(Log FILES ${SRC_LOG})

set(SRC_OBJECT
    "FileDirectory.cpp"
    "FileDirectory.h"
    "ObjectDirectory.cpp"
    "ObjectDirectory.h"
)

source_group(Object FILES ${SRC_OBJECT})

set(SRC_REGISTRY
    "Hive.h"
    "HiveQuery.cpp"
    "HiveQuery.h"
    "RegFind.cpp"
    "RegFind.h"
    "RegFindConfig.cpp"
    "RegFindConfig.h"
    "RegistryWalker.cpp"
    "RegistryWalker.h"
)

source_group(Registry FILES ${SRC_REGISTRY})

set(SRC_RUNNINGCODE
    "Authenticode.cpp"
    "Authenticode.h"
    "AutoRuns.cpp"
    "AutoRuns.h"
    "MSIExtension.cpp"
    "MSIExtension.h"
    "PSAPIExtension.cpp"
    "PSAPIExtension.h"
    "RunningCode.cpp"
    "RunningCode.h"
    "RunningProcesses.cpp"
    "RunningProcesses.h"
    "TaskTracker.cpp"
    "TaskTracker.h"
    "WinTrustExtension.cpp"
    "WinTrustExtension.h"
)

source_group(RunningCode FILES ${SRC_RUNNINGCODE})

set(SRC_UTILITIES
    "Convert.h"
    "OrcException.cpp"
    "OrcException.h"
    "Flags.cpp"
    "Flags.h"
    "Utils/BufferView.h"
    "Utils/BufferSpan.h"
    "Utils/Dump.h"
    "Utils/EnumFlags.h"
    "Utils/Guard.h"
    "Utils/Guard/Winsock.h"
    "Utils/Guard/Winsock.cpp"
    "Utils/Locker.h"
    "Utils/MakeArray.h"
    "Utils/MapFile.h"
    "Utils/MapFile.cpp"
    "Utils/MetaPtr.h"
    "Utils/Result.h"
    "Utils/Round.h"
    "Utils/StackStash.h"
    "Utils/String.cpp"
    "Utils/String.h"
    "Utils/Time.cpp"
    "Utils/Time.h"
    "Utils/TypeTraits.h"
    "Utils/Uri.cpp"
    "Utils/Uri.h"
    "Utils/WinApi.cpp"
    "Utils/WinApi.h"
    "Utils/StdStream/LazyFileStreambuf.cpp"
    "Utils/StdStream/LazyFileStreambuf.h"
    "Utils/StdStream/LazyFileStream.cpp"
    "Utils/StdStream/LazyFileStream.h"
    "Utils/StdStream/StandardOutput.h"
    "Utils/StdStream/StandardOutput.cpp"
    "Utils/StdStream/StandardOutputFileTee.h"
    "Utils/StdStream/StandardOutputFileTee.cpp"
    "Utils/StdStream/StreamRedirector.cpp"
    "Utils/StdStream/StreamRedirector.h"
    "Utils/StdStream/Tee.cpp"
    "Utils/StdStream/Tee.h"
    "Utils/StdStream/WideStreambufConverter.cpp"
    "Utils/StdStream/WideStreambufConverter.h"
    "Utils/StdStream/StandardOutputWriteConsoleRedirection.h"
    "Utils/StdStream/StandardOutputWriteConsoleRedirection.cpp"
)

source_group(Utilities FILES ${SRC_UTILITIES})

set(SRC_UTILITIES_MEMORY
    "BinaryBuffer.cpp"
    "BinaryBuffer.h"
    "Buffer.h"
    "CircularStorage.h"
    "HeapStorage.h"
    "ObjectStorage.h"
)

source_group(Utilities\\Memory FILES ${SRC_UTILITIES_MEMORY})

set(SRC_UTILITIES_PARAMETERS
    "OutputSpec.cpp"
    "OutputSpec.h"
    "OutputSpecTypes.h"
    "OutputSpecTypes.cpp"
    "ParameterCheck.cpp"
    "ParameterCheck.h"
    "Temporary.cpp"
    "Temporary.h"
)

source_group(Utilities\\Parameters FILES ${SRC_UTILITIES_PARAMETERS})

set(SRC_UTILITIES_RESOURCES
    "EmbeddedResource.h"
    "EmbeddedResource_Embed.cpp"
    "EmbeddedResource_Extract.cpp"
)

source_group(Utilities\\Resources FILES ${SRC_UTILITIES_RESOURCES})

set(SRC_UTILITIES_STRINGS
    "CaseInsensitive.h"
    "Strings.h"
    "Unicode.cpp"
    "Unicode.h"
    "Unicode_XmlComment.cpp"
    "Unicode_XmlElement.cpp"
    "Unicode_XmlPair.cpp"
    "Unicode_XmlString.cpp"
    "WideAnsi.cpp"
    "WideAnsi.h"
)

source_group(Utilities\\Strings FILES ${SRC_UTILITIES_STRINGS})

set(SRC_UTILITIES_SYSTEM
    "CriticalSection.h"
    "CryptoUtilities.cpp"
    "CryptoUtilities.h"
    "DriverMgmt.cpp"
    "DriverMgmt.h"
    "HypervisorType.h"
    "HypervisorType.cpp"
    "JobObject.cpp"
    "JobObject.h"
    "Privilege.cpp"
    "Privilege.h"
    "ProfileList.cpp"
    "ProfileList.h"
    "Registry.cpp"
    "Registry.h"
    "Robustness.cpp"
    "Robustness.h"
    "SecurityDescriptor.cpp"
    "SecurityDescriptor.h"
    "SystemDetails.cpp"
    "SystemDetails.h"
    "SystemIdentity.cpp"
    "SystemIdentity.h"
    "WMIUtil.cpp"
    "WMIUtil.h"
)

source_group(Utilities\\System FILES ${SRC_UTILITIES_SYSTEM})

set(SRC_UTILITIES_TEST
    "UnitTestHelper.cpp"
    "UnitTestHelper.h"
)

source_group(Utilities\\Test FILES ${SRC_UTILITIES_TEST})

add_library(OrcLib
    STATIC
        "stdafx.h"
        ${SRC_COMMAND}
        ${SRC_COMMON}
        ${SRC_CONFIG}
        ${SRC_DISK}
        ${SRC_DISK_FILESYSTEM}
        ${SRC_DISK_FILESYSTEM_FAT}
        ${SRC_DISK_FILESYSTEM_NTFS}
        ${SRC_DISK_FILESYSTEM_NTFS_FILEINFO}
        ${SRC_DISK_FILESYSTEM_NTFS_MFT}
        ${SRC_DISK_FILESYSTEM_NTFS_MFT_RECORD}
        ${SRC_DISK_FILESYSTEM_NTFS_MFT_USN}
        ${SRC_DISK_LOCATION}
        ${SRC_DISK_VOLUME}
        ${SRC_EXTENSIONLIBRARIES}
        ${SRC_EXTENSIONLIBRARIES_YARA}
        ${SRC_FILE_FORMAT}
        ${SRC_INOUT}
        ${SRC_INOUT_ARCHIVE}
        ${SRC_INOUT_ARCHIVE_SEVENZIP}
        ${SRC_INOUT_ARCHIVER}
        ${SRC_INOUT_BYTESTREAM}
        ${SRC_INOUT_BYTESTREAM_CRYPTOSTREAM}
        ${SRC_INOUT_BYTESTREAM_FSSTREAM_FATSTREAM}
        ${SRC_INOUT_BYTESTREAM_FSSTREAM_NTFSSTREAM}
        ${SRC_INOUT_BYTESTREAM_MESSAGESTREAM}
        ${SRC_INOUT_BYTESTREAM_SYSTEMSTREAM}
        ${SRC_INOUT_BYTESTREAM_UTILITYSTREAM}
        ${SRC_INOUT_BYTESTREAM_WRAPPERSTREAM}
        ${SRC_INOUT_CONCURRENT}
        ${SRC_INOUT_DOWNLOAD}
        ${SRC_INOUT_IMPORT}
        ${SRC_INOUT_LOGPARSER}
        ${SRC_INOUT_STRUCTUREDOUTPUT}
        ${SRC_INOUT_STRUCTUREDOUTPUT_XML}
        ${SRC_INOUT_STRUCTUREDOUTPUT_JSON}
        ${SRC_INOUT_TABLEOUTPUT}
        ${SRC_INOUT_TABLEOUTPUT_CSV}
        ${SRC_INOUT_TABLEOUTPUT_PARQUET}
        ${SRC_INOUT_TABLEOUTPUT_APACHE_ORC}
        ${SRC_INOUT_TABLEOUTPUT_SQL}
        ${SRC_INOUT_CONSOLE}
        ${SRC_FILESYSTEM}
        ${SRC_STREAM}
        ${SRC_TEXT}
        ${SRC_TEXT_FMT}
        ${SRC_TEXT_FMT_FWD}
        ${SRC_TEXT_PRINT}
        ${SRC_INOUT_UPLOAD}
        ${SRC_LOG}
        ${SRC_OBJECT}
        ${SRC_REGISTRY}
        ${SRC_RUNNINGCODE}
        ${SRC_UTILITIES}
        ${SRC_UTILITIES_MEMORY}
        ${SRC_UTILITIES_PARAMETERS}
        ${SRC_UTILITIES_RESOURCES}
        ${SRC_UTILITIES_SYSTEM}
        ${SRC_UTILITIES_STRINGS}
        ${SRC_UTILITIES_TEST}
        ${SRC_UTILITIES_WINAPIHELPER}
)

target_include_directories(OrcLib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${Boost_INCLUDE_DIRS}
)

target_link_libraries(OrcLib
    PUBLIC
        7zip::7zip
        7zip::extras
        Microsoft.GSL::GSL
        psapi.lib
        Wintrust.lib
        Crypt32.lib
        fmt::fmt
        yara::yara
        ws2_32.lib
        Iphlpapi.lib
)

find_package(RapidJSON CONFIG REQUIRED)
target_include_directories(OrcLib PRIVATE ${RAPIDJSON_INCLUDE_DIRS})

if(ORC_BUILD_SSDEEP)
    find_package(ssdeep CONFIG REQUIRED)
    target_link_libraries(OrcLib PUBLIC ssdeep::fuzzy)
endif()

if(NOT ORC_DISABLE_PRECOMPILED_HEADERS)
    target_precompile_headers(OrcLib PRIVATE stdafx.h)
endif()

set_target_properties(OrcLib PROPERTIES FOLDER "${ORC_ROOT_VIRTUAL_FOLDER}")

target_link_options(OrcLib PUBLIC "/STACK:4194304")
