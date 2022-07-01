# Changelog
All notable changes to this project will be documented in this file.

## 1.1.4 - 01.05.2022

### Changed
- Campaign details are not immediately sent out as a separate event but are attached to the first screen event.

## 1.1.3 - 10.05.2022

### Changed
- The `sendSocialInteractionWithAction`, `sendExceptionWithDescription` and `sendApplicationDownload` events are no longer tracked as screen views but as custom events.
- The `target` argument in the `sendSocialInteractionWithAction` method and `isFatal` in the `sendExceptionWithDescription` method are no longer used and will soon be removed from the signatures of these methods.

## 1.1.2 - 07.03.2022

### Changed
- `Target` argument in the social interaction method to optional
- Custom dimensions are set for one event only, not for all events

### Added
- Validation of URLs that are sent with events
- Interaction parameter to `sendContentInteraction` event


## 1.1.1 - 10.02.2022

### Changed
  
- Removed gzip compression handling
 
## 1.1.0 - 08.02.2022
   
### Added
- Possibility to change visitor ID
- Dry run functionality added
- The possibility to start a new session
- Gzip compression
- Track traffic source by platform and version of SDK
 
### Changed
- The algorithm related to session timeout has been improved
 
### Fixed
 
- Tracking ecommerce transactions: handling of thousandths separator fixed in `price()` method; incorrect conversion from cents to dollars has been fixed
- Fixed an issue of missing e-mail in the request
- Fixed percent-encoding in requests
- Fixed an issue with incorrect URL keyword parsing in the Tracking campaigns method
- Anonymisation has been improved and optimised. Now, when anonymisation is enabled, device ID, e-mail and user ID are not sent to the adience manager
- Minor fixes and improvements
